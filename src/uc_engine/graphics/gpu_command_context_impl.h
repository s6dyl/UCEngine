#include "pch.h"

#include <uc_public/graphics/gpu_command_context.h>

#include <uc_dev/gx/dx12/dx12.h>


namespace UniqueCreator
{
    namespace Graphics
    {
        class GpuCommandContext::Impl
        {
            public:

            Impl() = default;
            Impl(uc::gx::dx12::gpu_command_context* context);

            uc::gx::dx12::gpu_command_context* m_context;
        };
    }
}


