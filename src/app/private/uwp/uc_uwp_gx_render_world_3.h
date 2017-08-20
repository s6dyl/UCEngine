#pragma once

#include <memory>
#include <vector>

#include <uc_dev/gx/dx12/dx12.h>
#include <uc_dev/gx/geo/indexed_geometry.h>

#include "uc_uwp_gx_render_world.h"

namespace uc
{
    namespace uwp
    {
        namespace gxu
        {
            class render_world_3 : public render_world
            {
                using base = render_world;

            public:

                render_world_3(initialize_context* ctx);
                virtual ~render_world_3();

            private:

                void do_update(update_context* ctx) override;
                gx::dx12::managed_graphics_command_context do_render(render_context* ctx) override;
                gx::dx12::managed_graphics_command_context do_render_depth(render_context* ctx) override;


                gx::geo::parametrized_geometry                                  m_bear;
                gx::dx12::managed_gpu_texture_2d                                m_texture_bear;

                gx::dx12::graphics_pipeline_state*                              m_textured;
                gx::dx12::graphics_pipeline_state*                              m_depth_prepass;


				math::managed_float4x4                                          m_bear_transform = math::make_float4x4();
            };
        }
    }
}
