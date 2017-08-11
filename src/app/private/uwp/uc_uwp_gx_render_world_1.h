#pragma once

#include <memory>
#include <vector>

#include <uc_dev/gx/dx12/dx12.h>
#include <uc_dev/gx/geo/indexed_geometry.h>
#include <uc_dev/gx/anm/animation_instance.h>
#include <uc_dev/gx/structs.h>

#include "uc_uwp_gx_render_world.h"

#include <malloc.h>

namespace uc
{
    namespace uwp
    {
        namespace gxu
        {
            class render_world_1 : public render_world
            {

                using base = render_world;

				struct skinned_draw_constants
				{
					math::float4x4                  m_world;
					std::array<math::float4x4, 127> m_joints_palette;

					skinned_draw_constants()
					{
						reset();
					}

					void reset()
					{
						m_world = math::identity_matrix();
						for (auto&& i : m_joints_palette)
						{
							i = math::identity_matrix();
						}
					}
				};

            public:

                render_world_1(initialize_context* ctx);
                virtual ~render_world_1();

            private:

                void do_update(update_context* ctx) override;
                gx::dx12::managed_graphics_command_context do_render(render_context* ctx) override;
                gx::dx12::managed_graphics_command_context do_render_depth(render_context* ctx) override;

                std::unique_ptr<gxu::skinned_render_object>      m_robot;

                gx::dx12::graphics_pipeline_state*                              m_textured_skinned;
                gx::dx12::graphics_pipeline_state*                              m_depth_prepass;

				lip::unique_lip_pointer<lip::skeleton>                          m_skeleton;
				std::vector< lip::unique_lip_pointer<lip::joint_animations> >	m_animations;

				std::vector < std::unique_ptr< gx::anm::skeleton_instance > >   m_skeleton_instance;
				std::vector < std::unique_ptr< gx::anm::animation_instance> >   m_animation_instance;

				std::vector < skinned_draw_constants >							m_draw_constants;

                //update state
				math::managed_float4x4                                          m_robot_transform = math::make_float4x4();
            };
        }
    }
}

