#pragma once

#include <uc_dev/util/noncopyable.h>

#include "uc_uwp_renderer_overlay_render_context.h"
#include <uc_dev/gx/dx12/cmd/graphics_command_context_utils.h>
namespace uc
{
    namespace uwp
    {
        namespace overlay
        {
            class page : public util::noncopyable
            {
                public:

                page( initialize_context* ctx );

                virtual ~page();

                void update( update_context* ctx);
                gx::dx12::managed_graphics_command_context render( render_context* ctx);

                private:

                virtual void do_update(update_context* ctx) = 0;
                virtual  gx::dx12::managed_graphics_command_context do_render( render_context* ctx ) = 0;
            };
        }
    }

}