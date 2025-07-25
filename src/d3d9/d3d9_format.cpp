#include "d3d9_format.h"
#include "d3d9_adapter.h"
#include "d3d9_names.h"

namespace dxvk {

  // It is also worth noting that the msb/lsb-ness is flipped between VK and D3D9.
  D3D9_VK_FORMAT_MAPPING ConvertFormatUnfixed(D3D9Format Format) {
    switch (Format) {
      case D3D9Format::Unknown: return {};

      case D3D9Format::R8G8B8: return {}; // Unsupported

      case D3D9Format::A8R8G8B8: return {
        VK_FORMAT_B8G8R8A8_UNORM,
        VK_FORMAT_B8G8R8A8_SRGB,
        VK_IMAGE_ASPECT_COLOR_BIT };

      case D3D9Format::X8R8G8B8: return {
        VK_FORMAT_B8G8R8A8_UNORM,
        VK_FORMAT_B8G8R8A8_SRGB,
        VK_IMAGE_ASPECT_COLOR_BIT,
        { VK_COMPONENT_SWIZZLE_R, VK_COMPONENT_SWIZZLE_G,
          VK_COMPONENT_SWIZZLE_B, VK_COMPONENT_SWIZZLE_ONE }};

      case D3D9Format::R5G6B5: return {
        VK_FORMAT_R5G6B5_UNORM_PACK16,
        VK_FORMAT_UNDEFINED,
        VK_IMAGE_ASPECT_COLOR_BIT};

      case D3D9Format::X1R5G5B5: return {
        VK_FORMAT_A1R5G5B5_UNORM_PACK16,
        VK_FORMAT_UNDEFINED,
        VK_IMAGE_ASPECT_COLOR_BIT,
        { VK_COMPONENT_SWIZZLE_R, VK_COMPONENT_SWIZZLE_G,
          VK_COMPONENT_SWIZZLE_B, VK_COMPONENT_SWIZZLE_ONE }};

      case D3D9Format::A1R5G5B5: return {
        VK_FORMAT_A1R5G5B5_UNORM_PACK16,
        VK_FORMAT_UNDEFINED,
        VK_IMAGE_ASPECT_COLOR_BIT };

      case D3D9Format::A4R4G4B4: return {
        VK_FORMAT_A4R4G4B4_UNORM_PACK16,
        VK_FORMAT_UNDEFINED,
        VK_IMAGE_ASPECT_COLOR_BIT };

      case D3D9Format::R3G3B2: return {}; // Unsupported

      case D3D9Format::A8: return {
        VK_FORMAT_R8_UNORM,
        VK_FORMAT_UNDEFINED,
        VK_IMAGE_ASPECT_COLOR_BIT,
        { VK_COMPONENT_SWIZZLE_ZERO, VK_COMPONENT_SWIZZLE_ZERO,
          VK_COMPONENT_SWIZZLE_ZERO, VK_COMPONENT_SWIZZLE_R }};

      case D3D9Format::A8R3G3B2: return {}; // Unsupported

      case D3D9Format::X4R4G4B4: return {
        VK_FORMAT_A4R4G4B4_UNORM_PACK16,
        VK_FORMAT_UNDEFINED,
        VK_IMAGE_ASPECT_COLOR_BIT };

      case D3D9Format::A2B10G10R10: return {
        VK_FORMAT_A2B10G10R10_UNORM_PACK32, // The A2 is out of place here. This should be investigated.
        VK_FORMAT_UNDEFINED,
        VK_IMAGE_ASPECT_COLOR_BIT };

      case D3D9Format::A8B8G8R8: return {
        VK_FORMAT_R8G8B8A8_UNORM,
        VK_FORMAT_R8G8B8A8_SRGB,
        VK_IMAGE_ASPECT_COLOR_BIT };

      case D3D9Format::X8B8G8R8: return {
        VK_FORMAT_R8G8B8A8_UNORM,
        VK_FORMAT_R8G8B8A8_SRGB,
        VK_IMAGE_ASPECT_COLOR_BIT,
        { VK_COMPONENT_SWIZZLE_R, VK_COMPONENT_SWIZZLE_G,
          VK_COMPONENT_SWIZZLE_B, VK_COMPONENT_SWIZZLE_ONE }};

      case D3D9Format::G16R16: return {
        VK_FORMAT_R16G16_UNORM,
        VK_FORMAT_UNDEFINED,
        VK_IMAGE_ASPECT_COLOR_BIT,
        { VK_COMPONENT_SWIZZLE_R,   VK_COMPONENT_SWIZZLE_G,
          VK_COMPONENT_SWIZZLE_ONE, VK_COMPONENT_SWIZZLE_ONE }};

      case D3D9Format::A2R10G10B10: return {
        VK_FORMAT_A2R10G10B10_UNORM_PACK32,
        VK_FORMAT_UNDEFINED,
        VK_IMAGE_ASPECT_COLOR_BIT };

      case D3D9Format::A16B16G16R16: return {
        VK_FORMAT_R16G16B16A16_UNORM,
        VK_FORMAT_UNDEFINED,
        VK_IMAGE_ASPECT_COLOR_BIT };

      case D3D9Format::A8P8: return {}; // Unsupported

      case D3D9Format::P8: return {}; // Unsupported

      case D3D9Format::L8: return {
        VK_FORMAT_R8_UNORM,
        VK_FORMAT_R8_SRGB,
        VK_IMAGE_ASPECT_COLOR_BIT,
        { VK_COMPONENT_SWIZZLE_R, VK_COMPONENT_SWIZZLE_R,
          VK_COMPONENT_SWIZZLE_R, VK_COMPONENT_SWIZZLE_ONE }};

      case D3D9Format::A8L8: return {
        VK_FORMAT_R8G8_UNORM,
        VK_FORMAT_UNDEFINED,
        VK_IMAGE_ASPECT_COLOR_BIT,
        { VK_COMPONENT_SWIZZLE_R, VK_COMPONENT_SWIZZLE_R,
          VK_COMPONENT_SWIZZLE_R, VK_COMPONENT_SWIZZLE_G }};

      case D3D9Format::A4L4: return {
        VK_FORMAT_R4G4_UNORM_PACK8,
        VK_FORMAT_UNDEFINED,
        VK_IMAGE_ASPECT_COLOR_BIT,
        { VK_COMPONENT_SWIZZLE_G, VK_COMPONENT_SWIZZLE_G,
          VK_COMPONENT_SWIZZLE_G, VK_COMPONENT_SWIZZLE_R }};

      case D3D9Format::V8U8: return {
        VK_FORMAT_R8G8_SNORM,
        VK_FORMAT_UNDEFINED,
        VK_IMAGE_ASPECT_COLOR_BIT,
        { VK_COMPONENT_SWIZZLE_R,   VK_COMPONENT_SWIZZLE_G,
          VK_COMPONENT_SWIZZLE_ONE, VK_COMPONENT_SWIZZLE_ONE }};

      case D3D9Format::L6V5U5: return {
        // Any PACK16 format will do...
        VK_FORMAT_B5G6R5_UNORM_PACK16,
        VK_FORMAT_UNDEFINED,
        VK_IMAGE_ASPECT_COLOR_BIT,
        { VK_COMPONENT_SWIZZLE_R, VK_COMPONENT_SWIZZLE_G,
          VK_COMPONENT_SWIZZLE_B, VK_COMPONENT_SWIZZLE_A },
        { D3D9ConversionFormat_L6V5U5,
        // Convert -> float (this is a mixed snorm and unorm type)
          VK_FORMAT_R16G16B16A16_SFLOAT } };

      case D3D9Format::X8L8V8U8: return {
        VK_FORMAT_B8G8R8A8_UNORM,
        VK_FORMAT_UNDEFINED,
        VK_IMAGE_ASPECT_COLOR_BIT,
        { VK_COMPONENT_SWIZZLE_R, VK_COMPONENT_SWIZZLE_G,
          VK_COMPONENT_SWIZZLE_B, VK_COMPONENT_SWIZZLE_ONE },
        { D3D9ConversionFormat_X8L8V8U8,
        // Convert -> float (this is a mixed snorm and unorm type)
          VK_FORMAT_R16G16B16A16_SFLOAT } };

      case D3D9Format::Q8W8V8U8: return {
        VK_FORMAT_R8G8B8A8_SNORM,
        VK_FORMAT_UNDEFINED,
        VK_IMAGE_ASPECT_COLOR_BIT };

      case D3D9Format::V16U16: return {
        VK_FORMAT_R16G16_SNORM,
        VK_FORMAT_UNDEFINED,
        VK_IMAGE_ASPECT_COLOR_BIT,
        { VK_COMPONENT_SWIZZLE_R,   VK_COMPONENT_SWIZZLE_G,
          VK_COMPONENT_SWIZZLE_ONE, VK_COMPONENT_SWIZZLE_ONE }};

      case D3D9Format::A2W10V10U10: return {
        VK_FORMAT_A2B10G10R10_UNORM_PACK32,
        VK_FORMAT_UNDEFINED,
        VK_IMAGE_ASPECT_COLOR_BIT,
        { VK_COMPONENT_SWIZZLE_R, VK_COMPONENT_SWIZZLE_G,
          VK_COMPONENT_SWIZZLE_B, VK_COMPONENT_SWIZZLE_A },
        { D3D9ConversionFormat_A2W10V10U10,
        // Convert -> float (this is a mixed snorm and unorm type)
          VK_FORMAT_R16G16B16A16_SFLOAT } };

      case D3D9Format::W11V11U10: return {
        VK_FORMAT_B10G11R11_UFLOAT_PACK32,
        VK_FORMAT_UNDEFINED,
        VK_IMAGE_ASPECT_COLOR_BIT,
        { VK_COMPONENT_SWIZZLE_R, VK_COMPONENT_SWIZZLE_G,
          VK_COMPONENT_SWIZZLE_B, VK_COMPONENT_SWIZZLE_ONE },
        { D3D9ConversionFormat_W11V11U10,
        // can't use B10G11R11 because this is a snorm type
          VK_FORMAT_R16G16B16A16_SNORM } };

      case D3D9Format::UYVY: return {
        VK_FORMAT_G8B8G8R8_422_UNORM,
        VK_FORMAT_UNDEFINED,
        VK_IMAGE_ASPECT_COLOR_BIT,
        { VK_COMPONENT_SWIZZLE_IDENTITY, VK_COMPONENT_SWIZZLE_IDENTITY,
          VK_COMPONENT_SWIZZLE_IDENTITY, VK_COMPONENT_SWIZZLE_IDENTITY },
        { D3D9ConversionFormat_UYVY, VK_FORMAT_B8G8R8A8_UNORM }
      };

      case D3D9Format::R8G8_B8G8: return {
        VK_FORMAT_G8B8G8R8_422_UNORM, // This format may have been _SCALED in DX9.
        VK_FORMAT_UNDEFINED,
        VK_IMAGE_ASPECT_COLOR_BIT };

      case D3D9Format::YUY2: return {
        VK_FORMAT_G8B8G8R8_422_UNORM,
        VK_FORMAT_UNDEFINED,
        VK_IMAGE_ASPECT_COLOR_BIT,
        { VK_COMPONENT_SWIZZLE_IDENTITY, VK_COMPONENT_SWIZZLE_IDENTITY,
          VK_COMPONENT_SWIZZLE_IDENTITY, VK_COMPONENT_SWIZZLE_IDENTITY },
        { D3D9ConversionFormat_YUY2, VK_FORMAT_B8G8R8A8_UNORM }
      };

      case D3D9Format::G8R8_G8B8: return {
        VK_FORMAT_B8G8R8G8_422_UNORM, // This format may have been _SCALED in DX9.
        VK_FORMAT_UNDEFINED,
        VK_IMAGE_ASPECT_COLOR_BIT };

      case D3D9Format::DXT1: return {
        VK_FORMAT_BC1_RGBA_UNORM_BLOCK,
        VK_FORMAT_BC1_RGBA_SRGB_BLOCK,
        VK_IMAGE_ASPECT_COLOR_BIT };

      case D3D9Format::DXT2: return {
        VK_FORMAT_BC2_UNORM_BLOCK,
        VK_FORMAT_BC2_SRGB_BLOCK,
        VK_IMAGE_ASPECT_COLOR_BIT };

      case D3D9Format::DXT3: return {
        VK_FORMAT_BC2_UNORM_BLOCK,
        VK_FORMAT_BC2_SRGB_BLOCK,
        VK_IMAGE_ASPECT_COLOR_BIT };

      case D3D9Format::DXT4: return {
        VK_FORMAT_BC3_UNORM_BLOCK,
        VK_FORMAT_BC3_SRGB_BLOCK,
        VK_IMAGE_ASPECT_COLOR_BIT };

      case D3D9Format::DXT5: return {
        VK_FORMAT_BC3_UNORM_BLOCK,
        VK_FORMAT_BC3_SRGB_BLOCK,
        VK_IMAGE_ASPECT_COLOR_BIT };

      case D3D9Format::D16_LOCKABLE: return {
        VK_FORMAT_D16_UNORM,
        VK_FORMAT_UNDEFINED,
        VK_IMAGE_ASPECT_DEPTH_BIT };

      case D3D9Format::D32: return {}; // Unsupported (everywhere)

      case D3D9Format::D15S1: return {}; // Unsupported (everywhere)

      case D3D9Format::D24S8: return {
        VK_FORMAT_D24_UNORM_S8_UINT,
        VK_FORMAT_UNDEFINED,
        VK_IMAGE_ASPECT_DEPTH_BIT | VK_IMAGE_ASPECT_STENCIL_BIT };

      case D3D9Format::D24X8: return {
        VK_FORMAT_D24_UNORM_S8_UINT,
        VK_FORMAT_UNDEFINED,
        VK_IMAGE_ASPECT_DEPTH_BIT };

      case D3D9Format::D24X4S4: return {}; // Unsupported (everywhere)

      case D3D9Format::D16: return {
        VK_FORMAT_D16_UNORM,
        VK_FORMAT_UNDEFINED,
        VK_IMAGE_ASPECT_DEPTH_BIT };

      case D3D9Format::D32F_LOCKABLE: return {
        VK_FORMAT_D32_SFLOAT,
        VK_FORMAT_UNDEFINED,
        VK_IMAGE_ASPECT_DEPTH_BIT };

      case D3D9Format::D24FS8: return {
        VK_FORMAT_D24_UNORM_S8_UINT,
        VK_FORMAT_UNDEFINED,
        VK_IMAGE_ASPECT_DEPTH_BIT | VK_IMAGE_ASPECT_STENCIL_BIT };

      case D3D9Format::D32_LOCKABLE: return {}; // Unsupported (everywhere)

      case D3D9Format::S8_LOCKABLE: return {}; // Unsupported (everywhere)

      case D3D9Format::L16: return {
        VK_FORMAT_R16_UNORM,
        VK_FORMAT_UNDEFINED,
        VK_IMAGE_ASPECT_COLOR_BIT,
        { VK_COMPONENT_SWIZZLE_R, VK_COMPONENT_SWIZZLE_R,
          VK_COMPONENT_SWIZZLE_R, VK_COMPONENT_SWIZZLE_ONE }};

      case D3D9Format::VERTEXDATA: return {
        VK_FORMAT_R8_UINT,
        VK_FORMAT_UNDEFINED,
        0 };

      case D3D9Format::INDEX16: return {
        VK_FORMAT_R16_UINT,
        VK_FORMAT_UNDEFINED,
        0 };

      case D3D9Format::INDEX32: return {
        VK_FORMAT_R32_UINT,
        VK_FORMAT_UNDEFINED,
        0 };

      case D3D9Format::Q16W16V16U16: return {
        VK_FORMAT_R16G16B16A16_SNORM,
        VK_FORMAT_UNDEFINED,
        VK_IMAGE_ASPECT_COLOR_BIT };

      case D3D9Format::MULTI2_ARGB8: return {}; // Unsupported

      case D3D9Format::R16F: return {
        VK_FORMAT_R16_SFLOAT,
        VK_FORMAT_UNDEFINED,
        VK_IMAGE_ASPECT_COLOR_BIT,
        { VK_COMPONENT_SWIZZLE_R,   VK_COMPONENT_SWIZZLE_ONE,
          VK_COMPONENT_SWIZZLE_ONE, VK_COMPONENT_SWIZZLE_ONE }};

      case D3D9Format::G16R16F: return {
        VK_FORMAT_R16G16_SFLOAT,
        VK_FORMAT_UNDEFINED,
        VK_IMAGE_ASPECT_COLOR_BIT,
        { VK_COMPONENT_SWIZZLE_R,   VK_COMPONENT_SWIZZLE_G,
          VK_COMPONENT_SWIZZLE_ONE, VK_COMPONENT_SWIZZLE_ONE }};

      case D3D9Format::A16B16G16R16F: return {
        VK_FORMAT_R16G16B16A16_SFLOAT,
        VK_FORMAT_UNDEFINED,
        VK_IMAGE_ASPECT_COLOR_BIT };

      case D3D9Format::R32F: return {
        VK_FORMAT_R32_SFLOAT,
        VK_FORMAT_UNDEFINED,
        VK_IMAGE_ASPECT_COLOR_BIT,
        { VK_COMPONENT_SWIZZLE_R,   VK_COMPONENT_SWIZZLE_ONE,
          VK_COMPONENT_SWIZZLE_ONE, VK_COMPONENT_SWIZZLE_ONE }};

      case D3D9Format::G32R32F: return {
        VK_FORMAT_R32G32_SFLOAT,
        VK_FORMAT_UNDEFINED,
        VK_IMAGE_ASPECT_COLOR_BIT,
        { VK_COMPONENT_SWIZZLE_R,   VK_COMPONENT_SWIZZLE_G,
          VK_COMPONENT_SWIZZLE_ONE, VK_COMPONENT_SWIZZLE_ONE }};

      case D3D9Format::A32B32G32R32F: return {
        VK_FORMAT_R32G32B32A32_SFLOAT,
        VK_FORMAT_UNDEFINED,
        VK_IMAGE_ASPECT_COLOR_BIT };

      case D3D9Format::CxV8U8: return {}; // Unsupported

      case D3D9Format::A1: return {}; // Unsupported

      case D3D9Format::A2B10G10R10_XR_BIAS: return {}; // Unsupported (everywhere)

      case D3D9Format::BINARYBUFFER: return {
        VK_FORMAT_R8_UINT,
        VK_FORMAT_UNDEFINED,
        0 };

      case D3D9Format::ATI1: return {
        VK_FORMAT_BC4_UNORM_BLOCK,
        VK_FORMAT_UNDEFINED,
        VK_IMAGE_ASPECT_COLOR_BIT,
        { VK_COMPONENT_SWIZZLE_R,    VK_COMPONENT_SWIZZLE_ZERO,
          VK_COMPONENT_SWIZZLE_ZERO, VK_COMPONENT_SWIZZLE_ONE }};

      case D3D9Format::ATI2: return {
        VK_FORMAT_BC5_UNORM_BLOCK,
        VK_FORMAT_UNDEFINED,
        VK_IMAGE_ASPECT_COLOR_BIT,
        { VK_COMPONENT_SWIZZLE_G,   VK_COMPONENT_SWIZZLE_R,
          VK_COMPONENT_SWIZZLE_ONE, VK_COMPONENT_SWIZZLE_ONE }};

      case D3D9Format::INST: return {}; // Driver hack, handled elsewhere

      case D3D9Format::DF24: return {
        VK_FORMAT_D24_UNORM_S8_UINT,
        VK_FORMAT_UNDEFINED,
        VK_IMAGE_ASPECT_DEPTH_BIT,
        { VK_COMPONENT_SWIZZLE_R,    VK_COMPONENT_SWIZZLE_ZERO,
          VK_COMPONENT_SWIZZLE_ZERO, VK_COMPONENT_SWIZZLE_ONE }};

      case D3D9Format::DF16: return {
        VK_FORMAT_D16_UNORM,
        VK_FORMAT_UNDEFINED,
        VK_IMAGE_ASPECT_DEPTH_BIT,
        { VK_COMPONENT_SWIZZLE_R,    VK_COMPONENT_SWIZZLE_ZERO,
          VK_COMPONENT_SWIZZLE_ZERO, VK_COMPONENT_SWIZZLE_ONE }};

      case D3D9Format::NULL_FORMAT: return {}; // Driver hack, handled elsewhere

      case D3D9Format::GET4: return {}; // Unsupported

      case D3D9Format::GET1: return {}; // Unsupported

      case D3D9Format::NVDB: return {}; // Driver hack, handled elsewhere

      case D3D9Format::A2M1: return {}; // Driver hack, handled elsewhere

      case D3D9Format::A2M0: return {}; // Driver hack, handled elsewhere

      case D3D9Format::ATOC: return {}; // Driver hack, handled elsewhere

      case D3D9Format::SSAA: return {}; // Driver hack, handled elsewhere

      case D3D9Format::INTZ: return {
        VK_FORMAT_D24_UNORM_S8_UINT,
        VK_FORMAT_UNDEFINED,
        VK_IMAGE_ASPECT_DEPTH_BIT | VK_IMAGE_ASPECT_STENCIL_BIT,
        { VK_COMPONENT_SWIZZLE_R, VK_COMPONENT_SWIZZLE_R,
          VK_COMPONENT_SWIZZLE_R, VK_COMPONENT_SWIZZLE_R }};

      case D3D9Format::NV12: return {
        VK_FORMAT_G8_B8R8_2PLANE_420_UNORM,
        VK_FORMAT_UNDEFINED,
        VK_IMAGE_ASPECT_COLOR_BIT,
        { VK_COMPONENT_SWIZZLE_IDENTITY, VK_COMPONENT_SWIZZLE_IDENTITY,
          VK_COMPONENT_SWIZZLE_IDENTITY, VK_COMPONENT_SWIZZLE_IDENTITY },
        { D3D9ConversionFormat_NV12, VK_FORMAT_B8G8R8A8_UNORM }
      };

      case D3D9Format::YV12: return {
        VK_FORMAT_G8_B8_R8_3PLANE_420_UNORM,
        VK_FORMAT_UNDEFINED,
        VK_IMAGE_ASPECT_COLOR_BIT,
        { VK_COMPONENT_SWIZZLE_IDENTITY, VK_COMPONENT_SWIZZLE_IDENTITY,
          VK_COMPONENT_SWIZZLE_IDENTITY, VK_COMPONENT_SWIZZLE_IDENTITY },
        { D3D9ConversionFormat_YV12, VK_FORMAT_B8G8R8A8_UNORM }
      };

      case D3D9Format::RAWZ: return {}; // Unsupported

      // EXT1, FXT1, GXT1 and HXT1 are checked for support
      // by D3D9 SAGE engine games (e.g. Command & Conquer 3)

      case D3D9Format::EXT1: return {}; // Unsupported (everywhere)

      case D3D9Format::FXT1: return {}; // Unsupported (everywhere)

      case D3D9Format::GXT1: return {}; // Unsupported (everywhere)

      case D3D9Format::HXT1: return {}; // Unsupported (everywhere)

      // AL16 and R16 FOURCCs are often checked for support by
      // various D3D8 and early D3D9 games. AR16 and L16 (FOURCC)
      // are also checked for support, but to a lesser extent.

      case D3D9Format::AL16: return {}; // Unsupported (everywhere)

      case D3D9Format::AR16: return {}; // Unsupported (everywhere)

      case D3D9Format::R16:  return {}; // Unsupported (everywhere)

      case D3D9Format::L16_FOURCC:  return {}; // Unsupported (everywhere)

      default:
        Logger::warn(str::format("ConvertFormat: Unknown format encountered: ", Format));
        return {}; // Unsupported
    }
  }

  // Block size of formats that require some form of alignment
  D3D9_FORMAT_BLOCK_SIZE GetFormatAlignedBlockSize(D3D9Format Format) {
    switch (Format) {
      case D3D9Format::DXT1:
      case D3D9Format::DXT2:
      case D3D9Format::DXT3:
      case D3D9Format::DXT4:
      case D3D9Format::DXT5:
      case D3D9Format::ATI1:
      case D3D9Format::ATI2:
        return { 4, 4, 1 };

      case D3D9Format::YUY2:
      case D3D9Format::UYVY:
        return { 2, 1, 1 };

      default:
        return {}; // Irrelevant or unknown block size
    }
  }

  D3D9VkFormatTable::D3D9VkFormatTable(
            D3D9Adapter*     pParent,
      const Rc<DxvkAdapter>& adapter,
      const D3D9Options&     options)
    : m_parent (pParent) {

    const uint32_t vendorId = m_parent->GetVendorId();
    const bool     isNvidia = vendorId == uint32_t(DxvkGpuVendor::Nvidia);
    const bool     isAmd    = vendorId == uint32_t(DxvkGpuVendor::Amd);
    const bool     isIntel  = vendorId == uint32_t(DxvkGpuVendor::Intel);

    // NVIDIA does not natively support any DF formats
    m_dfSupport = !isNvidia ? options.supportDFFormats : false;
    m_x4r4g4b4Support = options.supportX4R4G4B4;
    // Only AMD supports D16_LOCKABLE natively
    m_d16lockableSupport = isAmd;

    // AMD do not support 24-bit depth buffers on Vulkan,
    // so we have to fall back to a 32-bit depth format.
    m_d24s8Support = !options.useD32forD24 &&
                     CheckImageFormatSupport(adapter, VK_FORMAT_D24_UNORM_S8_UINT,
      VK_FORMAT_FEATURE_2_DEPTH_STENCIL_ATTACHMENT_BIT |
      VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_BIT);

    // NVIDIA do not support 16-bit depth buffers with stencil on Vulkan,
    // so we have to fall back to a 32-bit depth format.
    m_d16s8Support = CheckImageFormatSupport(adapter, VK_FORMAT_D16_UNORM_S8_UINT,
      VK_FORMAT_FEATURE_2_DEPTH_STENCIL_ATTACHMENT_BIT |
      VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_BIT);

    // AMD and Nvidia support D32F_LOCKABLE natively (Intel does not)
    m_d32flockableSupport = !isIntel;
    // Only Intel supports D24FS8 natively
    m_d24fs8Support = isIntel;

    if (!m_d24s8Support)
      Logger::info("D3D9: VK_FORMAT_D24_UNORM_S8_UINT -> VK_FORMAT_D32_SFLOAT_S8_UINT");

    if (!m_d16s8Support) {
      if (m_d24s8Support)
        Logger::info("D3D9: VK_FORMAT_D16_UNORM_S8_UINT -> VK_FORMAT_D24_UNORM_S8_UINT");
      else
        Logger::info("D3D9: VK_FORMAT_D16_UNORM_S8_UINT -> VK_FORMAT_D32_SFLOAT_S8_UINT");
    }
  }

  D3D9_VK_FORMAT_MAPPING D3D9VkFormatTable::GetFormatMapping(
          D3D9Format          Format) const {
    D3D9_VK_FORMAT_MAPPING mapping = ConvertFormatUnfixed(Format);

    if (Format == D3D9Format::X4R4G4B4 && !m_x4r4g4b4Support)
      return D3D9_VK_FORMAT_MAPPING();

    // W11V11U10 is only supported by d3d8
    if (Format == D3D9Format::W11V11U10 && !m_parent->IsD3D8Compatible())
      return D3D9_VK_FORMAT_MAPPING();

    if (Format == D3D9Format::D16_LOCKABLE && !m_d16lockableSupport)
      return D3D9_VK_FORMAT_MAPPING();

    if (Format == D3D9Format::DF16 && !m_dfSupport)
      return D3D9_VK_FORMAT_MAPPING();

    if (Format == D3D9Format::DF24 && !m_dfSupport)
      return D3D9_VK_FORMAT_MAPPING();

    if (Format == D3D9Format::D32F_LOCKABLE && !m_d32flockableSupport)
      return D3D9_VK_FORMAT_MAPPING();

    if (Format == D3D9Format::D24FS8 && !m_d24fs8Support)
      return D3D9_VK_FORMAT_MAPPING();

    if (!m_d24s8Support && mapping.FormatColor == VK_FORMAT_D24_UNORM_S8_UINT)
      mapping.FormatColor = (mapping.Aspect & VK_IMAGE_ASPECT_STENCIL_BIT) ? VK_FORMAT_D32_SFLOAT_S8_UINT : VK_FORMAT_D32_SFLOAT;

    if (!m_d16s8Support && mapping.FormatColor == VK_FORMAT_D16_UNORM_S8_UINT)
      mapping.FormatColor = m_d24s8Support ? VK_FORMAT_D24_UNORM_S8_UINT : VK_FORMAT_D32_SFLOAT_S8_UINT;

    return mapping;
  }


  const DxvkFormatInfo* D3D9VkFormatTable::GetUnsupportedFormatInfo(
    D3D9Format            Format) const {
    static const DxvkFormatInfo r8b8g8        = { 3, VK_IMAGE_ASPECT_COLOR_BIT };
    static const DxvkFormatInfo r3g3b2        = { 1, VK_IMAGE_ASPECT_COLOR_BIT };
    static const DxvkFormatInfo x4r4g4b4      = { 2, VK_IMAGE_ASPECT_COLOR_BIT };
    static const DxvkFormatInfo a8r3g3b2      = { 2, VK_IMAGE_ASPECT_COLOR_BIT };
    static const DxvkFormatInfo a8p8          = { 2, VK_IMAGE_ASPECT_COLOR_BIT };
    static const DxvkFormatInfo p8            = { 1, VK_IMAGE_ASPECT_COLOR_BIT };
    static const DxvkFormatInfo w11v11u10     = { 4, VK_IMAGE_ASPECT_COLOR_BIT };
    static const DxvkFormatInfo cxv8u8        = { 2, VK_IMAGE_ASPECT_COLOR_BIT };
    // Unsupported and potentially unsupported lockable depth formats need to be
    // listed here in order to allow for the creation of offscreen plain surfaces
    static const DxvkFormatInfo d16_lockable  = { 2, VK_IMAGE_ASPECT_DEPTH_BIT };
    static const DxvkFormatInfo d32f_lockable = { 4, VK_IMAGE_ASPECT_DEPTH_BIT };
    static const DxvkFormatInfo d32_lockable  = { 4, VK_IMAGE_ASPECT_DEPTH_BIT };
    static const DxvkFormatInfo s8_lockable   = { 1, VK_IMAGE_ASPECT_STENCIL_BIT };
    static const DxvkFormatInfo unknown       = {};

    switch (Format) {
      case D3D9Format::R8G8B8:
        return &r8b8g8;

      case D3D9Format::R3G3B2:
        return &r3g3b2;

      // potentially unsupported through a config option
      case D3D9Format::X4R4G4B4:
        return &x4r4g4b4;

      case D3D9Format::A8R3G3B2:
        return &a8r3g3b2;

      case D3D9Format::A8P8:
        return &a8p8;

      case D3D9Format::P8:
        return &p8;

      // only supported by d3d8
      case D3D9Format::W11V11U10:
        return &w11v11u10;

      // MULTI2_ARGB8 -> Don't have a clue what this is.

      case D3D9Format::CxV8U8:
        return &cxv8u8;

      // A1 -> Doesn't map nicely here cause it's not byte aligned.
      // Gonna just pretend that doesn't exist until something
      // depends on that.

      // only supported on AMD
      case D3D9Format::D16_LOCKABLE:
        return &d16_lockable;

      // unsupported on Intel
      case D3D9Format::D32F_LOCKABLE:
        return &d32f_lockable;

      // only considered on d3d9Ex interfaces
      case D3D9Format::D32_LOCKABLE:
        if (m_parent->IsExtended())
          return &d32_lockable;

        [[fallthrough]];

      // only considered on d3d9Ex interfaces
      case D3D9Format::S8_LOCKABLE:
        if (m_parent->IsExtended())
          return &s8_lockable;

        [[fallthrough]];

      default:
        return &unknown;
    }
  }


  bool D3D9VkFormatTable::CheckImageFormatSupport(
    const Rc<DxvkAdapter>&      Adapter,
          VkFormat              Format,
          VkFormatFeatureFlags2 Features) const {
    DxvkFormatFeatures supported = Adapter->getFormatFeatures(Format);

    return (supported.linear  & Features) == Features
        || (supported.optimal & Features) == Features;
  }

}