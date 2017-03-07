begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This file defines BMP file header data structures.  Copyright (c) 2006 - 2011, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under the terms and conditions of the BSD License which accompanies this distribution.  The full text of the license may be found at http://opensource.org/licenses/bsd-license.php  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BMP_H_
end_ifndef

begin_define
define|#
directive|define
name|_BMP_H_
end_define

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Blue
decl_stmt|;
name|UINT8
name|Green
decl_stmt|;
name|UINT8
name|Red
decl_stmt|;
name|UINT8
name|Reserved
decl_stmt|;
block|}
name|BMP_COLOR_MAP
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|CHAR8
name|CharB
decl_stmt|;
name|CHAR8
name|CharM
decl_stmt|;
name|UINT32
name|Size
decl_stmt|;
name|UINT16
name|Reserved
index|[
literal|2
index|]
decl_stmt|;
name|UINT32
name|ImageOffset
decl_stmt|;
name|UINT32
name|HeaderSize
decl_stmt|;
name|UINT32
name|PixelWidth
decl_stmt|;
name|UINT32
name|PixelHeight
decl_stmt|;
name|UINT16
name|Planes
decl_stmt|;
comment|///< Must be 1
name|UINT16
name|BitPerPixel
decl_stmt|;
comment|///< 1, 4, 8, or 24
name|UINT32
name|CompressionType
decl_stmt|;
name|UINT32
name|ImageSize
decl_stmt|;
comment|///< Compressed image size in bytes
name|UINT32
name|XPixelsPerMeter
decl_stmt|;
name|UINT32
name|YPixelsPerMeter
decl_stmt|;
name|UINT32
name|NumberOfColors
decl_stmt|;
name|UINT32
name|ImportantColors
decl_stmt|;
block|}
name|BMP_IMAGE_HEADER
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

end_unit

