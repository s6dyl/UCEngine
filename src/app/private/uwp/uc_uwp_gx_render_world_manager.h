#pragma once

#include <array>
#include <memory>
#include <ppltasks.h>

#include <uc_dev/util/noncopyable.h>
#include "uc_uwp_gx_render_world.h"
#include "uc_uwp_gx_render_world_id.h"



namespace uc
{
    namespace uwp
    {
        namespace gxu
        {
            class render_world_manager : public util::noncopyable
            {
                public:

                render_world_manager( initialize_context* c );

                ~render_world_manager();

                void show_world( world_id page );
                void hide_world(  );

                void update( update_context* ctx );
                
                gx::dx12::managed_graphics_command_context render( render_context* ctx );
                gx::dx12::managed_graphics_command_context render_depth(render_context* ctx);

                gx::pinhole_camera* camera()
                {
                    return m_world ? m_world->camera() : nullptr;
                }

                const gx::pinhole_camera* camera() const
                {
                    return m_world ? m_world->camera() : nullptr;
                }

                private:

                std::shared_ptr< render_world > m_world;
                initialize_context              m_initialize_context;

                concurrency::task<void>         m_loading_world;
            };
        }
    }

}