#pragma once

#include <uc_dev/lip/lip.h>

#include <uc_dev/gx/lip/base.h>
#include <uc_dev/gx/lip/structs.h>
#include <uc_dev/gx/lip/math.h>

namespace uc
{
    namespace lip
    {
        using index = uint32_t;

        struct indices
        {
            lip::reloc_array < index > m_data;

            size_t size() const
            {
                return m_data.size();
            }

            index* data()
            {
                return m_data.data();
            }

            const index* data() const
            {
                return m_data.data();
            }

            indices()
            {

            }

#if defined(UC_TOOLS)
            indices(const lip::reloc_array<index>& data) : m_data(data)
            {

            }

            indices(lip::reloc_array<index>&& data) : m_data( std::move(data) )
            {

            }

            indices(const indices& o) : m_data(o.m_data)
            {}

            indices(indices&& o) : m_data(std::move(o.m_data))
            {}

            indices& operator=(const indices& o)
            {
                m_data = o.m_data;
                return *this;
            }

            indices& operator=(indices&& o)
            {
                m_data = std::move(o.m_data);
                return *this;
            }
#endif
            explicit indices(const lip::load_context& c) : m_data(c)
            {

            }

#if defined(UC_TOOLS)
            bool operator==(const indices & o) const
            {
                return m_data == o.m_data;
            }

            bool operator!=(const indices& o) const 
            {
                return m_data != o.m_data;
            }
#endif


            LIP_DECLARE_RTTI()
        };

        LIP_DECLARE_TYPE_ID(uc::lip::indices)

        inline size_t size(const indices& p)
        {
            return p.size() * sizeof(index);
        }

        struct positions
        {
            lip::reloc_array < point3 > m_data;

            positions()
            {

            }

            explicit positions(const lip::load_context& c) : m_data(c)
            {

            }

#if defined(UC_TOOLS)            
            positions(const lip::reloc_array<point3>& data) : m_data(data)
            {

            }

            positions(lip::reloc_array<point3>&& data) : m_data( std::move(data) )
            {}

            positions(const positions& o) : m_data(o.m_data)
            {}

            positions( positions&& o ) : m_data(std::move(o.m_data))
            {}

            positions& operator=(const positions& o)
            {
                m_data = o.m_data;
                return *this;
            }

            positions& operator=(positions&& o)
            {
                m_data = std::move(o.m_data);
                return *this;
            }

            ~positions() = default;
#endif
            size_t size() const
            {
                return m_data.size();
            }

            point3* data()
            {
                return m_data.data();
            }

            const point3* data() const
            {
                return m_data.data();
            }

#if defined(UC_TOOLS)            
            bool operator ==(const positions& rhs) const
            {
                return m_data == rhs.m_data;
            }

            bool operator !=(const positions& rhs) const
            {
                return m_data != rhs.m_data;
            }
#endif

            LIP_DECLARE_RTTI()
        };

        inline size_t size(const positions& p )
        {
            return p.size() * sizeof(float3);
        }

        LIP_DECLARE_TYPE_ID(uc::lip::positions)
        LIP_DECLARE_TYPE_ID(uc::lip::reloc_array < float3 >)
        LIP_DECLARE_TYPE_ID(uc::lip::reloc_array < point3 >)

        struct model
        {
            indices                         m_indices;
            positions                       m_positions;

            model()
            {

            }

#if defined(UC_TOOLS)

            model(const indices &ind, const positions &pos) : m_indices(ind), m_positions(pos)
            {}

            model(const model& mod) : m_indices(mod.m_indices), m_positions(mod.m_positions)
            {}

            model(model&& o) : m_indices(std::move(o.m_indices)), m_positions(std::move(o.m_positions))
            {}

            model& operator=(const model& o)
            {
                m_indices = o.m_indices;
                m_positions = o.m_positions;
                return *this;
            }

            model& operator=(model&& o)
            {
                m_indices = std::move(o.m_indices);
                m_positions = std::move(o.m_positions);
                return *this;
            }
               
#endif
            explicit model(const lip::load_context& c) : m_indices(c), m_positions(c)
            {

            }

#if defined(UC_TOOLS)
            bool operator ==( const model& rhs) const
            {
                return m_indices == rhs.m_indices && m_positions == rhs.m_positions;
            }

            bool operator !=( model& rhs ) const
            {
                return m_indices != rhs.m_indices || m_positions != rhs.m_positions;
            }
#endif

            LIP_DECLARE_RTTI()
        };

        LIP_DECLARE_TYPE_ID(uc::lip::model)

        struct uvs
        {
            lip::reloc_array < point2 > m_data;

            uvs()
            {

            }

            explicit uvs(const lip::load_context& c) : m_data(c)
            {

            }

            size_t size() const
            {
                return m_data.size();
            }

            point2* data()
            {
                return m_data.data();
            }

            const point2* data() const
            {
                return m_data.data();
            }

            LIP_DECLARE_RTTI()
        };

        LIP_DECLARE_TYPE_ID(uc::lip::uvs)
        LIP_DECLARE_TYPE_ID(uc::lip::reloc_array < float2 >)
        LIP_DECLARE_TYPE_ID(uc::lip::reloc_array < point2 >)

        inline size_t size(const uvs& p)
        {
            return p.size() * sizeof(float2);
        }

        struct parametrized_model
        {
            indices                         m_indices;
            positions                       m_positions;
            uvs                             m_uv;

            parametrized_model()
            {

            }

            parametrized_model(indices ind, positions pos, uvs uv) : m_indices(ind), m_positions(pos), m_uv(uv) {}

            explicit parametrized_model(const lip::load_context& c) : m_indices(c), m_positions(c), m_uv(c)
            {

            }

            LIP_DECLARE_RTTI()
        };

        LIP_DECLARE_TYPE_ID(uc::lip::parametrized_model)

        //todo: make this serializale
        enum class storage_format : uint16_t
        {
                unknown  = 0               ,
                r32_g32_b32_a32_float = 2  ,
                r16_g16_b16_a16_float = 10 ,
                r16_g16_b16_a16_unorm = 11 ,
                r8_g8_b8_a8_unorm = 28     ,
                b8_g8_r8_a8_unorm = 87     ,
                b8_g8_r8_x8_unorm = 88     ,
                r10_g10_b10_xr_bias_a2_unorm = 89 ,
                r10_g10_b10_a2_unorm = 24         ,
                b5_g5_r5_a1_unorm = 86            ,
                b5_g6_r5_unorm = 85               ,
                r32_float = 41                    ,
                r16_float = 54                    ,
                r16_unorm = 56                    ,
                r8_unorm  = 61                    ,
                a8_unorm  = 65                    ,
                r32_g32_b32_float = 6             ,
                bc1 = 70                          ,
                bc2 = 73                          ,
                bc3 = 76                          ,
                bc4 = 79                          ,
                bc5 = 82
        };

        enum class view_format : uint16_t
        {
            unknown = 0,
            r32_g32_b32_a32_float = 2,
            r16_g16_b16_a16_float = 10,
            r16_g16_b16_a16_unorm = 11,
            r8_g8_b8_a8_unorm = 28,
            b8_g8_r8_a8_unorm = 87,
            b8_g8_r8_x8_unorm = 88,
            r10_g10_b10_xr_bias_a2_unorm = 89,
            r10_g10_b10_a2_unorm = 24,
            b5_g5_r5_a1_unorm = 86,
            b5_g6_r5_unorm = 85,
            r32_float = 41,
            r16_float = 54,
            r16_unorm = 56,
            r8_unorm            = 61,
            a8_unorm            = 65,
            r32_g32_b32_float   = 6,
            bc1_unorm           = 71,
            bc1_unorm_srgb      = 72,
            bc2_unorm           = 74,
            bc2_unorm_srgb      = 75,
            bc3_unorm           = 77,
            bc3_unorm_srgb      = 78,
            bc4_unorm           = 80,
            bc4_snorm           = 81,
            bc5_unorm           = 83,
            bc5_snorm           = 84
        };

        struct texture2d
        {
            lip::reloc_array < uint8_t > m_data;
                
            uint16_t m_width;
            uint16_t m_height;
            uint16_t m_mip_levels;
            uint16_t m_storage_format;
            uint16_t m_view_format;
  
            size_t size() const
            {
                return m_data.size();
            }

            const void* data() const
            {
                return m_data.data();
            }

            storage_format storage() const
            {
                return static_cast<storage_format>(m_storage_format);
            }

            view_format view() const
            {
                return static_cast<view_format>(m_view_format);
            }

            texture2d() : m_storage_format(0), m_width(0), m_height(0), m_mip_levels(0), m_view_format(0)
            {

            }

            explicit texture2d(const lip::load_context& c) : m_data(c)
            {

            }

            LIP_DECLARE_RTTI()
        };
        
        LIP_DECLARE_TYPE_ID(uc::lip::texture2d)

        struct textured_model : public parametrized_model
        {
            using base = parametrized_model;

            texture2d m_texture;

            const texture2d* texture() const
            {
                return &m_texture;
            }

            texture2d* texture()
            {
                return &m_texture;
            }

            textured_model()
            {

            }
            
            explicit textured_model(const lip::load_context& c) : base( c),  m_texture(c)
            {

            }

            LIP_DECLARE_RTTI()
        };

        LIP_DECLARE_TYPE_ID(uc::lip::textured_model)

        struct primitive_range
        {
            uint32_t m_begin;
            uint32_t m_end;

            LIP_DECLARE_RTTI()
        };

        LIP_DECLARE_TYPE_ID(uc::lip::primitive_range)

        struct multi_textured_model : public parametrized_model
        {
            using base = parametrized_model;

            lip::reloc_array < texture2d >          m_textures;
            lip::reloc_array < primitive_range >    m_primitive_ranges;
            
            multi_textured_model()
            {

            }

            explicit multi_textured_model(const lip::load_context& c) : base( c)
                , m_textures(c)
                ,  m_primitive_ranges(c)
            {

            }

            LIP_DECLARE_RTTI()
        };

        LIP_DECLARE_TYPE_ID(uc::lip::reloc_array < texture2d >)
        LIP_DECLARE_TYPE_ID(uc::lip::reloc_array < primitive_range >)
        LIP_DECLARE_TYPE_ID(uc::lip::multi_textured_model)

        struct skinned_model : public multi_textured_model
        {
            using base = multi_textured_model;

            lip::reloc_array < float4 >          m_blend_weights;
            lip::reloc_array < ubyte4 >          m_blend_indices;

            skinned_model()
            {

            }

            explicit skinned_model(const lip::load_context& c) : base(c)
                , m_blend_weights(c)
                , m_blend_indices(c)
            {

            }

            LIP_DECLARE_RTTI()
        };

        LIP_DECLARE_TYPE_ID(uc::lip::skinned_model)
        LIP_DECLARE_TYPE_ID(uc::lip::reloc_array < float4 >)
        LIP_DECLARE_TYPE_ID(uc::lip::reloc_array < ubyte4 >)
        LIP_DECLARE_TYPE_ID(uc::lip::reloc_array < uint4 > )
    }
}