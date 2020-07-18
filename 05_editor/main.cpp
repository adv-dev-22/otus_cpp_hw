#include "editor_core.h"
#include "document_parameters.h"
#include "shapes_2d.h"
#include <memory>
#include <string>

using namespace GraphicalEditorCore;

int main(int argc, char * argv []) {

    using PrecType = float;
    auto up_editor_core = std::make_unique<EditorCore<PrecType>>();
    auto shp_doc_params = std::make_shared<DocumentParameters<ColorEngineUniform>>();

    shp_doc_params->setWidth(22000);
    auto & document = up_editor_core->create_document(shp_doc_params);

    // Create triangle
    auto up_triangle_01 = std::make_unique<TriangleShape2D<PrecType>>(1);
    up_triangle_01->moveVertex( 1.0,  2.0, 0);
    up_triangle_01->moveVertex(-3.0,  2.0, 1);
    up_triangle_01->moveVertex(-1.0, -3.0, 2);

    // Create circle
    auto up_circle_02 = std::make_unique<CircleShape2D<PrecType>>(2);
    up_circle_02->moveVertex(45., 0., 0);
    up_circle_02->moveCenter(-22., 34.);

    // Create Shapes for composite and composite
    auto up_triangle_03 = std::make_unique<TriangleShape2D<PrecType>>(3);
    up_triangle_03->moveVertex( 10.0, -2.0, 0);
    up_triangle_03->moveVertex(-30.0, -2.0, 1);
    up_triangle_03->moveVertex(-10.0,  3.0, 2);
    auto up_circle_04 = std::make_unique<CircleShape2D<PrecType>>(4);
    up_circle_04->moveVertex(4., 0., 0);
    up_circle_04->moveCenter(-2., 4.);
    auto up_composite_05 =std::make_unique<CompositeShape2D<PrecType>>(5);
    up_composite_05->add(std::move(up_triangle_03));
    up_composite_05->add(std::move(up_circle_04));

    document.add_shape(std::move(up_triangle_01));
    document.add_shape(std::move(up_circle_02));
    document.add_shape(std::move(up_composite_05));

    const std::string filename1("editor_01.txt");
//    up_editor_core->save(filename1);

    document.remove_shape(2);

    const std::string filename2("editor_02.txt");
//    up_editor_core->save(filename2);


    // create yet another editor
    // load its data from file

    auto up_editor_restore = std::make_unique<EditorCore<PrecType>>();
    //up_editor_restore->load(filename);

    // .. get some data;

    return 0;
}

// End of the file

