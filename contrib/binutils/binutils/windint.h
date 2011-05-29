begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* windint.h -- internal header file for windres program.    Copyright 1997, 1998, 1999, 2000, 2001, 2002, 2003, 2005, 2007    Free Software Foundation, Inc.    Written by Kai Tietz, Onevision.     This file is part of GNU Binutils.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA    02110-1301, USA.  */
end_comment

begin_include
include|#
directive|include
file|"winduni.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|WINDINT_H
end_ifndef

begin_define
define|#
directive|define
name|WINDINT_H
end_define

begin_comment
comment|/* Use bfd_size_type to ensure a sufficient number of bits.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DEFINED_RC_UINT_TYPE
end_ifndef

begin_define
define|#
directive|define
name|DEFINED_RC_UINT_TYPE
end_define

begin_typedef
typedef|typedef
name|bfd_size_type
name|rc_uint_type
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Resource directory structure.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|res_hdr
block|{
name|rc_uint_type
name|data_size
decl_stmt|;
name|rc_uint_type
name|header_size
decl_stmt|;
block|}
name|res_hdr
typedef|;
end_typedef

begin_struct
struct|struct
name|__attribute__
argument_list|(
argument|(__packed__)
argument_list|)
name|bin_res_hdr
block|{
name|bfd_byte
name|data_size
index|[
literal|4
index|]
decl_stmt|;
name|bfd_byte
name|header_size
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BIN_RES_HDR_SIZE
value|8
end_define

begin_struct
struct|struct
name|__attribute__
argument_list|(
argument|(__packed__)
argument_list|)
name|bin_res_id
block|{
name|bfd_byte
name|sig
index|[
literal|2
index|]
decl_stmt|;
comment|/* Has to be 0xffff for unnamed ids.  */
name|bfd_byte
name|id
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BIN_RES_ID
value|4
end_define

begin_comment
comment|/* This structure is used when converting resource information to    binary.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|bindata
block|{
comment|/* Next data.  */
name|struct
name|bindata
modifier|*
name|next
decl_stmt|;
comment|/* Length of data.  */
name|rc_uint_type
name|length
decl_stmt|;
comment|/* Data.  */
name|bfd_byte
modifier|*
name|data
decl_stmt|;
block|}
name|bindata
typedef|;
end_typedef

begin_comment
comment|/* This structure is used when converting resource information to    coff.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|coff_res_data
block|{
comment|/* Next data.  */
name|struct
name|coff_res_data
modifier|*
name|next
decl_stmt|;
comment|/* Length of data.  */
name|rc_uint_type
name|length
decl_stmt|;
comment|/* Data.  */
specifier|const
name|struct
name|rc_res_resource
modifier|*
name|res
decl_stmt|;
block|}
name|coff_res_data
typedef|;
end_typedef

begin_comment
comment|/* We represent resources internally as a tree, similar to the tree    used in the .rsrc section of a COFF file.  The root is a    rc_res_directory structure.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rc_res_directory
block|{
comment|/* Resource flags.  According to the MS docs, this is currently      always zero.  */
name|rc_uint_type
name|characteristics
decl_stmt|;
comment|/* Time/date stamp.  */
name|rc_uint_type
name|time
decl_stmt|;
comment|/* Major version number.  */
name|rc_uint_type
name|major
decl_stmt|;
comment|/* Minor version number.  */
name|rc_uint_type
name|minor
decl_stmt|;
comment|/* Directory entries.  */
name|struct
name|rc_res_entry
modifier|*
name|entries
decl_stmt|;
block|}
name|rc_res_directory
typedef|;
end_typedef

begin_comment
comment|/* A resource ID is stored in a rc_res_id structure.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rc_res_id
block|{
comment|/* Non-zero if this entry has a name rather than an ID.  */
name|rc_uint_type
name|named
range|:
literal|1
decl_stmt|;
union|union
block|{
comment|/* If the named field is non-zero, this is the name.  */
struct|struct
block|{
comment|/* Length of the name.  */
name|rc_uint_type
name|length
decl_stmt|;
comment|/* Pointer to the name, which is a Unicode string.  */
name|unichar
modifier|*
name|name
decl_stmt|;
block|}
name|n
struct|;
comment|/* If the named field is zero, this is the ID.  */
name|rc_uint_type
name|id
decl_stmt|;
block|}
name|u
union|;
block|}
name|rc_res_id
typedef|;
end_typedef

begin_comment
comment|/* Each entry in the tree is a rc_res_entry structure.  We mix    directories and resources because in a COFF file all entries in a    directory are sorted together, whether the entries are    subdirectories or resources.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rc_res_entry
block|{
comment|/* Next entry.  */
name|struct
name|rc_res_entry
modifier|*
name|next
decl_stmt|;
comment|/* Resource ID.  */
name|rc_res_id
name|id
decl_stmt|;
comment|/* Non-zero if this entry is a subdirectory rather than a leaf.  */
name|rc_uint_type
name|subdir
range|:
literal|1
decl_stmt|;
union|union
block|{
comment|/* If the subdir field is non-zero, this is a pointer to the        subdirectory.  */
name|rc_res_directory
modifier|*
name|dir
decl_stmt|;
comment|/* If the subdir field is zero, this is a pointer to the resource        data.  */
name|struct
name|rc_res_resource
modifier|*
name|res
decl_stmt|;
block|}
name|u
union|;
block|}
name|rc_res_entry
typedef|;
end_typedef

begin_comment
comment|/* Types of resources.  */
end_comment

begin_enum
enum|enum
name|rc_res_type
block|{
name|RES_TYPE_UNINITIALIZED
block|,
name|RES_TYPE_ACCELERATOR
block|,
name|RES_TYPE_BITMAP
block|,
name|RES_TYPE_CURSOR
block|,
name|RES_TYPE_GROUP_CURSOR
block|,
name|RES_TYPE_DIALOG
block|,
name|RES_TYPE_FONT
block|,
name|RES_TYPE_FONTDIR
block|,
name|RES_TYPE_ICON
block|,
name|RES_TYPE_GROUP_ICON
block|,
name|RES_TYPE_MENU
block|,
name|RES_TYPE_MESSAGETABLE
block|,
name|RES_TYPE_RCDATA
block|,
name|RES_TYPE_STRINGTABLE
block|,
name|RES_TYPE_USERDATA
block|,
name|RES_TYPE_VERSIONINFO
block|,
name|RES_TYPE_DLGINCLUDE
block|,
name|RES_TYPE_PLUGPLAY
block|,
name|RES_TYPE_VXD
block|,
name|RES_TYPE_ANICURSOR
block|,
name|RES_TYPE_ANIICON
block|,
name|RES_TYPE_DLGINIT
block|,
name|RES_TYPE_TOOLBAR
block|}
enum|;
end_enum

begin_comment
comment|/* A res file and a COFF file store information differently.  The    res_info structures holds data which in a res file is stored with    each resource, but in a COFF file is stored elsewhere.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rc_res_res_info
block|{
comment|/* Language.  In a COFF file, the third level of the directory is      keyed by the language, so the language of a resource is defined      by its location in the resource tree.  */
name|rc_uint_type
name|language
decl_stmt|;
comment|/* Characteristics of the resource.  Entirely user defined.  In a      COFF file, the rc_res_directory structure has a characteristics      field, but I don't know if it's related to the one in the res      file.  */
name|rc_uint_type
name|characteristics
decl_stmt|;
comment|/* Version of the resource.  Entirely user defined.  In a COFF file,      the rc_res_directory structure has a characteristics field, but I      don't know if it's related to the one in the res file.  */
name|rc_uint_type
name|version
decl_stmt|;
comment|/* Memory flags.  This is a combination of the MEMFLAG values      defined below.  Most of these values are historical, and are not      meaningful for win32.  I don't think there is any way to store      this information in a COFF file.  */
name|rc_uint_type
name|memflags
decl_stmt|;
block|}
name|rc_res_res_info
typedef|;
end_typedef

begin_comment
comment|/* Binary layout of rc_res_info.  */
end_comment

begin_struct
struct|struct
name|__attribute__
argument_list|(
argument|(__packed__)
argument_list|)
name|bin_res_info
block|{
name|bfd_byte
name|version
index|[
literal|4
index|]
decl_stmt|;
name|bfd_byte
name|memflags
index|[
literal|2
index|]
decl_stmt|;
name|bfd_byte
name|language
index|[
literal|2
index|]
decl_stmt|;
name|bfd_byte
name|version2
index|[
literal|4
index|]
decl_stmt|;
name|bfd_byte
name|characteristics
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BIN_RES_INFO_SIZE
value|16
end_define

begin_comment
comment|/* Each resource in a COFF file has some information which can does    not appear in a res file.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rc_res_coff_info
block|{
comment|/* The code page used for the data.  I don't really know what this      should be.  It has something todo with ASCII to Unicode encoding.  */
name|rc_uint_type
name|codepage
decl_stmt|;
comment|/* A resource entry in a COFF file has a reserved field, which we      record here when reading a COFF file.  When writing a COFF file,      we set this field to zero.  */
name|rc_uint_type
name|reserved
decl_stmt|;
block|}
name|rc_res_coff_info
typedef|;
end_typedef

begin_comment
comment|/* Resource data is stored in a rc_res_resource structure.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rc_res_resource
block|{
comment|/* The type of resource.  */
name|enum
name|rc_res_type
name|type
decl_stmt|;
comment|/* The data for the resource.  */
union|union
block|{
struct|struct
block|{
name|rc_uint_type
name|length
decl_stmt|;
specifier|const
name|bfd_byte
modifier|*
name|data
decl_stmt|;
block|}
name|data
struct|;
name|struct
name|rc_accelerator
modifier|*
name|acc
decl_stmt|;
name|struct
name|rc_cursor
modifier|*
name|cursor
decl_stmt|;
name|struct
name|rc_group_cursor
modifier|*
name|group_cursor
decl_stmt|;
name|struct
name|rc_dialog
modifier|*
name|dialog
decl_stmt|;
name|struct
name|rc_fontdir
modifier|*
name|fontdir
decl_stmt|;
name|struct
name|rc_group_icon
modifier|*
name|group_icon
decl_stmt|;
name|struct
name|rc_menu
modifier|*
name|menu
decl_stmt|;
name|struct
name|rc_rcdata_item
modifier|*
name|rcdata
decl_stmt|;
name|struct
name|rc_stringtable
modifier|*
name|stringtable
decl_stmt|;
name|struct
name|rc_rcdata_item
modifier|*
name|userdata
decl_stmt|;
name|struct
name|rc_versioninfo
modifier|*
name|versioninfo
decl_stmt|;
name|struct
name|rc_toolbar
modifier|*
name|toolbar
decl_stmt|;
block|}
name|u
union|;
comment|/* Information from a res file.  */
name|struct
name|rc_res_res_info
name|res_info
decl_stmt|;
comment|/* Information from a COFF file.  */
name|rc_res_coff_info
name|coff_info
decl_stmt|;
block|}
name|rc_res_resource
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SUBLANG_SHIFT
value|10
end_define

begin_comment
comment|/* Memory flags in the memflags field of a rc_res_resource.  */
end_comment

begin_define
define|#
directive|define
name|MEMFLAG_MOVEABLE
value|0x10
end_define

begin_define
define|#
directive|define
name|MEMFLAG_PURE
value|0x20
end_define

begin_define
define|#
directive|define
name|MEMFLAG_PRELOAD
value|0x40
end_define

begin_define
define|#
directive|define
name|MEMFLAG_DISCARDABLE
value|0x1000
end_define

begin_comment
comment|/* Standard resource type codes.  These are used in the ID field of a    rc_res_entry structure.  */
end_comment

begin_define
define|#
directive|define
name|RT_CURSOR
value|1
end_define

begin_define
define|#
directive|define
name|RT_BITMAP
value|2
end_define

begin_define
define|#
directive|define
name|RT_ICON
value|3
end_define

begin_define
define|#
directive|define
name|RT_MENU
value|4
end_define

begin_define
define|#
directive|define
name|RT_DIALOG
value|5
end_define

begin_define
define|#
directive|define
name|RT_STRING
value|6
end_define

begin_define
define|#
directive|define
name|RT_FONTDIR
value|7
end_define

begin_define
define|#
directive|define
name|RT_FONT
value|8
end_define

begin_define
define|#
directive|define
name|RT_ACCELERATOR
value|9
end_define

begin_define
define|#
directive|define
name|RT_RCDATA
value|10
end_define

begin_define
define|#
directive|define
name|RT_MESSAGETABLE
value|11
end_define

begin_define
define|#
directive|define
name|RT_GROUP_CURSOR
value|12
end_define

begin_define
define|#
directive|define
name|RT_GROUP_ICON
value|14
end_define

begin_define
define|#
directive|define
name|RT_VERSION
value|16
end_define

begin_define
define|#
directive|define
name|RT_DLGINCLUDE
value|17
end_define

begin_define
define|#
directive|define
name|RT_PLUGPLAY
value|19
end_define

begin_define
define|#
directive|define
name|RT_VXD
value|20
end_define

begin_define
define|#
directive|define
name|RT_ANICURSOR
value|21
end_define

begin_define
define|#
directive|define
name|RT_ANIICON
value|22
end_define

begin_define
define|#
directive|define
name|RT_HTML
value|23
end_define

begin_define
define|#
directive|define
name|RT_MANIFEST
value|24
end_define

begin_define
define|#
directive|define
name|RT_DLGINIT
value|240
end_define

begin_define
define|#
directive|define
name|RT_TOOLBAR
value|241
end_define

begin_comment
comment|/* An accelerator resource is a linked list of these structures.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rc_accelerator
block|{
comment|/* Next accelerator.  */
name|struct
name|rc_accelerator
modifier|*
name|next
decl_stmt|;
comment|/* Flags.  A combination of the ACC values defined below.  */
name|rc_uint_type
name|flags
decl_stmt|;
comment|/* Key value.  */
name|rc_uint_type
name|key
decl_stmt|;
comment|/* Resource ID.  */
name|rc_uint_type
name|id
decl_stmt|;
block|}
name|rc_accelerator
typedef|;
end_typedef

begin_struct
struct|struct
name|__attribute__
argument_list|(
argument|(__packed__)
argument_list|)
name|bin_accelerator
block|{
name|bfd_byte
name|flags
index|[
literal|2
index|]
decl_stmt|;
name|bfd_byte
name|key
index|[
literal|2
index|]
decl_stmt|;
name|bfd_byte
name|id
index|[
literal|2
index|]
decl_stmt|;
name|bfd_byte
name|pad
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BIN_ACCELERATOR_SIZE
value|8
end_define

begin_comment
comment|/* Accelerator flags in the flags field of a rc_accelerator.    These are the same values that appear in a res file.  I hope.  */
end_comment

begin_define
define|#
directive|define
name|ACC_VIRTKEY
value|0x01
end_define

begin_define
define|#
directive|define
name|ACC_NOINVERT
value|0x02
end_define

begin_define
define|#
directive|define
name|ACC_SHIFT
value|0x04
end_define

begin_define
define|#
directive|define
name|ACC_CONTROL
value|0x08
end_define

begin_define
define|#
directive|define
name|ACC_ALT
value|0x10
end_define

begin_define
define|#
directive|define
name|ACC_LAST
value|0x80
end_define

begin_comment
comment|/* A cursor resource.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rc_cursor
block|{
comment|/* X coordinate of hotspot.  */
name|bfd_signed_vma
name|xhotspot
decl_stmt|;
comment|/* Y coordinate of hotspot.  */
name|bfd_signed_vma
name|yhotspot
decl_stmt|;
comment|/* Length of bitmap data.  */
name|rc_uint_type
name|length
decl_stmt|;
comment|/* Data.  */
specifier|const
name|bfd_byte
modifier|*
name|data
decl_stmt|;
block|}
name|rc_cursor
typedef|;
end_typedef

begin_struct
struct|struct
name|__attribute__
argument_list|(
argument|(__packed__)
argument_list|)
name|bin_cursor
block|{
name|bfd_byte
name|xhotspot
index|[
literal|2
index|]
decl_stmt|;
name|bfd_byte
name|yhotspot
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BIN_CURSOR_SIZE
value|4
end_define

begin_comment
comment|/* A group_cursor resource is a list of rc_i_group_cursor structures.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rc_group_cursor
block|{
comment|/* Next cursor in group.  */
name|struct
name|rc_group_cursor
modifier|*
name|next
decl_stmt|;
comment|/* Width.  */
name|rc_uint_type
name|width
decl_stmt|;
comment|/* Height.  */
name|rc_uint_type
name|height
decl_stmt|;
comment|/* Planes.  */
name|rc_uint_type
name|planes
decl_stmt|;
comment|/* Bits per pixel.  */
name|rc_uint_type
name|bits
decl_stmt|;
comment|/* Number of bytes in cursor resource.  */
name|rc_uint_type
name|bytes
decl_stmt|;
comment|/* Index of cursor resource.  */
name|rc_uint_type
name|index
decl_stmt|;
block|}
name|rc_group_cursor
typedef|;
end_typedef

begin_struct
struct|struct
name|__attribute__
argument_list|(
argument|(__packed__)
argument_list|)
name|bin_group_cursor_item
block|{
name|bfd_byte
name|width
index|[
literal|2
index|]
decl_stmt|;
name|bfd_byte
name|height
index|[
literal|2
index|]
decl_stmt|;
name|bfd_byte
name|planes
index|[
literal|2
index|]
decl_stmt|;
name|bfd_byte
name|bits
index|[
literal|2
index|]
decl_stmt|;
name|bfd_byte
name|bytes
index|[
literal|4
index|]
decl_stmt|;
name|bfd_byte
name|index
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BIN_GROUP_CURSOR_ITEM_SIZE
value|14
end_define

begin_struct
struct|struct
name|__attribute__
argument_list|(
argument|(__packed__)
argument_list|)
name|bin_group_cursor
block|{
name|bfd_byte
name|sig1
index|[
literal|2
index|]
decl_stmt|;
name|bfd_byte
name|sig2
index|[
literal|2
index|]
decl_stmt|;
name|bfd_byte
name|nitems
index|[
literal|2
index|]
decl_stmt|;
comment|/* struct bin_group_cursor_item item[nitems]; */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BIN_GROUP_CURSOR_SIZE
value|6
end_define

begin_comment
comment|/* A dialog resource.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rc_dialog
block|{
comment|/* Basic window style.  */
name|unsigned
name|int
name|style
decl_stmt|;
comment|/* Extended window style.  */
name|rc_uint_type
name|exstyle
decl_stmt|;
comment|/* X coordinate.  */
name|rc_uint_type
name|x
decl_stmt|;
comment|/* Y coordinate.  */
name|rc_uint_type
name|y
decl_stmt|;
comment|/* Width.  */
name|rc_uint_type
name|width
decl_stmt|;
comment|/* Height.  */
name|rc_uint_type
name|height
decl_stmt|;
comment|/* Menu name.  */
name|rc_res_id
name|menu
decl_stmt|;
comment|/* Class name.  */
name|rc_res_id
name|class
decl_stmt|;
comment|/* Caption.  */
name|unichar
modifier|*
name|caption
decl_stmt|;
comment|/* Font point size.  */
name|rc_uint_type
name|pointsize
decl_stmt|;
comment|/* Font name.  */
name|unichar
modifier|*
name|font
decl_stmt|;
comment|/* Extended information for a dialogex.  */
name|struct
name|rc_dialog_ex
modifier|*
name|ex
decl_stmt|;
comment|/* Controls.  */
name|struct
name|rc_dialog_control
modifier|*
name|controls
decl_stmt|;
block|}
name|rc_dialog
typedef|;
end_typedef

begin_struct
struct|struct
name|__attribute__
argument_list|(
argument|(__packed__)
argument_list|)
name|bin_dialog
block|{
name|bfd_byte
name|style
index|[
literal|4
index|]
decl_stmt|;
name|bfd_byte
name|exstyle
index|[
literal|4
index|]
decl_stmt|;
name|bfd_byte
name|off
index|[
literal|2
index|]
decl_stmt|;
name|bfd_byte
name|x
index|[
literal|2
index|]
decl_stmt|;
name|bfd_byte
name|y
index|[
literal|2
index|]
decl_stmt|;
name|bfd_byte
name|width
index|[
literal|2
index|]
decl_stmt|;
name|bfd_byte
name|height
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BIN_DIALOG_SIZE
value|18
end_define

begin_comment
comment|/* An extended dialog has additional information.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rc_dialog_ex
block|{
comment|/* Help ID.  */
name|rc_uint_type
name|help
decl_stmt|;
comment|/* Font weight.  */
name|rc_uint_type
name|weight
decl_stmt|;
comment|/* Whether the font is italic.  */
name|bfd_byte
name|italic
decl_stmt|;
comment|/* Character set.  */
name|bfd_byte
name|charset
decl_stmt|;
block|}
name|rc_dialog_ex
typedef|;
end_typedef

begin_struct
struct|struct
name|__attribute__
argument_list|(
argument|(__packed__)
argument_list|)
name|bin_dialogex
block|{
name|bfd_byte
name|sig1
index|[
literal|2
index|]
decl_stmt|;
name|bfd_byte
name|sig2
index|[
literal|2
index|]
decl_stmt|;
name|bfd_byte
name|help
index|[
literal|4
index|]
decl_stmt|;
name|bfd_byte
name|exstyle
index|[
literal|4
index|]
decl_stmt|;
name|bfd_byte
name|style
index|[
literal|4
index|]
decl_stmt|;
name|bfd_byte
name|off
index|[
literal|2
index|]
decl_stmt|;
name|bfd_byte
name|x
index|[
literal|2
index|]
decl_stmt|;
name|bfd_byte
name|y
index|[
literal|2
index|]
decl_stmt|;
name|bfd_byte
name|width
index|[
literal|2
index|]
decl_stmt|;
name|bfd_byte
name|height
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BIN_DIALOGEX_SIZE
value|26
end_define

begin_struct
struct|struct
name|__attribute__
argument_list|(
argument|(__packed__)
argument_list|)
name|bin_dialogfont
block|{
name|bfd_byte
name|pointsize
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BIN_DIALOGFONT_SIZE
value|2
end_define

begin_struct
struct|struct
name|__attribute__
argument_list|(
argument|(__packed__)
argument_list|)
name|bin_dialogexfont
block|{
name|bfd_byte
name|pointsize
index|[
literal|2
index|]
decl_stmt|;
name|bfd_byte
name|weight
index|[
literal|2
index|]
decl_stmt|;
name|bfd_byte
name|italic
index|[
literal|1
index|]
decl_stmt|;
name|bfd_byte
name|charset
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BIN_DIALOGEXFONT_SIZE
value|6
end_define

begin_comment
comment|/* Window style flags, from the winsup Defines.h header file.  These    can appear in the style field of a rc_dialog or a rc_dialog_control.  */
end_comment

begin_define
define|#
directive|define
name|CW_USEDEFAULT
value|0x80000000
end_define

begin_define
define|#
directive|define
name|WS_BORDER
value|0x800000L
end_define

begin_define
define|#
directive|define
name|WS_CAPTION
value|0xc00000L
end_define

begin_define
define|#
directive|define
name|WS_CHILD
value|0x40000000L
end_define

begin_define
define|#
directive|define
name|WS_CHILDWINDOW
value|0x40000000L
end_define

begin_define
define|#
directive|define
name|WS_CLIPCHILDREN
value|0x2000000L
end_define

begin_define
define|#
directive|define
name|WS_CLIPSIBLINGS
value|0x4000000L
end_define

begin_define
define|#
directive|define
name|WS_DISABLED
value|0x8000000L
end_define

begin_define
define|#
directive|define
name|WS_DLGFRAME
value|0x400000L
end_define

begin_define
define|#
directive|define
name|WS_GROUP
value|0x20000L
end_define

begin_define
define|#
directive|define
name|WS_HSCROLL
value|0x100000L
end_define

begin_define
define|#
directive|define
name|WS_ICONIC
value|0x20000000L
end_define

begin_define
define|#
directive|define
name|WS_MAXIMIZE
value|0x1000000L
end_define

begin_define
define|#
directive|define
name|WS_MAXIMIZEBOX
value|0x10000L
end_define

begin_define
define|#
directive|define
name|WS_MINIMIZE
value|0x20000000L
end_define

begin_define
define|#
directive|define
name|WS_MINIMIZEBOX
value|0x20000L
end_define

begin_define
define|#
directive|define
name|WS_OVERLAPPED
value|0L
end_define

begin_define
define|#
directive|define
name|WS_OVERLAPPEDWINDOW
value|0xcf0000L
end_define

begin_define
define|#
directive|define
name|WS_POPUP
value|0x80000000L
end_define

begin_define
define|#
directive|define
name|WS_POPUPWINDOW
value|0x80880000L
end_define

begin_define
define|#
directive|define
name|WS_SIZEBOX
value|0x40000L
end_define

begin_define
define|#
directive|define
name|WS_SYSMENU
value|0x80000L
end_define

begin_define
define|#
directive|define
name|WS_TABSTOP
value|0x10000L
end_define

begin_define
define|#
directive|define
name|WS_THICKFRAME
value|0x40000L
end_define

begin_define
define|#
directive|define
name|WS_TILED
value|0L
end_define

begin_define
define|#
directive|define
name|WS_TILEDWINDOW
value|0xcf0000L
end_define

begin_define
define|#
directive|define
name|WS_VISIBLE
value|0x10000000L
end_define

begin_define
define|#
directive|define
name|WS_VSCROLL
value|0x200000L
end_define

begin_define
define|#
directive|define
name|MDIS_ALLCHILDSTYLES
value|0x1
end_define

begin_define
define|#
directive|define
name|BS_3STATE
value|0x5L
end_define

begin_define
define|#
directive|define
name|BS_AUTO3STATE
value|0x6L
end_define

begin_define
define|#
directive|define
name|BS_AUTOCHECKBOX
value|0x3L
end_define

begin_define
define|#
directive|define
name|BS_AUTORADIOBUTTON
value|0x9L
end_define

begin_define
define|#
directive|define
name|BS_BITMAP
value|0x80L
end_define

begin_define
define|#
directive|define
name|BS_BOTTOM
value|0x800L
end_define

begin_define
define|#
directive|define
name|BS_CENTER
value|0x300L
end_define

begin_define
define|#
directive|define
name|BS_CHECKBOX
value|0x2L
end_define

begin_define
define|#
directive|define
name|BS_DEFPUSHBUTTON
value|0x1L
end_define

begin_define
define|#
directive|define
name|BS_GROUPBOX
value|0x7L
end_define

begin_define
define|#
directive|define
name|BS_ICON
value|0x40L
end_define

begin_define
define|#
directive|define
name|BS_LEFT
value|0x100L
end_define

begin_define
define|#
directive|define
name|BS_LEFTTEXT
value|0x20L
end_define

begin_define
define|#
directive|define
name|BS_MULTILINE
value|0x2000L
end_define

begin_define
define|#
directive|define
name|BS_NOTIFY
value|0x4000L
end_define

begin_define
define|#
directive|define
name|BS_OWNERDRAW
value|0xbL
end_define

begin_define
define|#
directive|define
name|BS_PUSHBOX
value|0xcL
end_define

begin_comment
comment|/* FIXME!  What should this be?  */
end_comment

begin_define
define|#
directive|define
name|BS_PUSHBUTTON
value|0L
end_define

begin_define
define|#
directive|define
name|BS_PUSHLIKE
value|0x1000L
end_define

begin_define
define|#
directive|define
name|BS_RADIOBUTTON
value|0x4L
end_define

begin_define
define|#
directive|define
name|BS_RIGHT
value|0x200L
end_define

begin_define
define|#
directive|define
name|BS_RIGHTBUTTON
value|0x20L
end_define

begin_define
define|#
directive|define
name|BS_TEXT
value|0L
end_define

begin_define
define|#
directive|define
name|BS_TOP
value|0x400L
end_define

begin_define
define|#
directive|define
name|BS_USERBUTTON
value|0x8L
end_define

begin_define
define|#
directive|define
name|BS_VCENTER
value|0xc00L
end_define

begin_define
define|#
directive|define
name|CBS_AUTOHSCROLL
value|0x40L
end_define

begin_define
define|#
directive|define
name|CBS_DISABLENOSCROLL
value|0x800L
end_define

begin_define
define|#
directive|define
name|CBS_DROPDOWN
value|0x2L
end_define

begin_define
define|#
directive|define
name|CBS_DROPDOWNLIST
value|0x3L
end_define

begin_define
define|#
directive|define
name|CBS_HASSTRINGS
value|0x200L
end_define

begin_define
define|#
directive|define
name|CBS_LOWERCASE
value|0x4000L
end_define

begin_define
define|#
directive|define
name|CBS_NOINTEGRALHEIGHT
value|0x400L
end_define

begin_define
define|#
directive|define
name|CBS_OEMCONVERT
value|0x80L
end_define

begin_define
define|#
directive|define
name|CBS_OWNERDRAWFIXED
value|0x10L
end_define

begin_define
define|#
directive|define
name|CBS_OWNERDRAWVARIABLE
value|0x20L
end_define

begin_define
define|#
directive|define
name|CBS_SIMPLE
value|0x1L
end_define

begin_define
define|#
directive|define
name|CBS_SORT
value|0x100L
end_define

begin_define
define|#
directive|define
name|CBS_UPPERCASE
value|0x2000L
end_define

begin_define
define|#
directive|define
name|ES_AUTOHSCROLL
value|0x80L
end_define

begin_define
define|#
directive|define
name|ES_AUTOVSCROLL
value|0x40L
end_define

begin_define
define|#
directive|define
name|ES_CENTER
value|0x1L
end_define

begin_define
define|#
directive|define
name|ES_LEFT
value|0L
end_define

begin_define
define|#
directive|define
name|ES_LOWERCASE
value|0x10L
end_define

begin_define
define|#
directive|define
name|ES_MULTILINE
value|0x4L
end_define

begin_define
define|#
directive|define
name|ES_NOHIDESEL
value|0x100L
end_define

begin_define
define|#
directive|define
name|ES_NUMBER
value|0x2000L
end_define

begin_define
define|#
directive|define
name|ES_OEMCONVERT
value|0x400L
end_define

begin_define
define|#
directive|define
name|ES_PASSWORD
value|0x20L
end_define

begin_define
define|#
directive|define
name|ES_READONLY
value|0x800L
end_define

begin_define
define|#
directive|define
name|ES_RIGHT
value|0x2L
end_define

begin_define
define|#
directive|define
name|ES_UPPERCASE
value|0x8L
end_define

begin_define
define|#
directive|define
name|ES_WANTRETURN
value|0x1000L
end_define

begin_define
define|#
directive|define
name|LBS_DISABLENOSCROLL
value|0x1000L
end_define

begin_define
define|#
directive|define
name|LBS_EXTENDEDSEL
value|0x800L
end_define

begin_define
define|#
directive|define
name|LBS_HASSTRINGS
value|0x40L
end_define

begin_define
define|#
directive|define
name|LBS_MULTICOLUMN
value|0x200L
end_define

begin_define
define|#
directive|define
name|LBS_MULTIPLESEL
value|0x8L
end_define

begin_define
define|#
directive|define
name|LBS_NODATA
value|0x2000L
end_define

begin_define
define|#
directive|define
name|LBS_NOINTEGRALHEIGHT
value|0x100L
end_define

begin_define
define|#
directive|define
name|LBS_NOREDRAW
value|0x4L
end_define

begin_define
define|#
directive|define
name|LBS_NOSEL
value|0x4000L
end_define

begin_define
define|#
directive|define
name|LBS_NOTIFY
value|0x1L
end_define

begin_define
define|#
directive|define
name|LBS_OWNERDRAWFIXED
value|0x10L
end_define

begin_define
define|#
directive|define
name|LBS_OWNERDRAWVARIABLE
value|0x20L
end_define

begin_define
define|#
directive|define
name|LBS_SORT
value|0x2L
end_define

begin_define
define|#
directive|define
name|LBS_STANDARD
value|0xa00003L
end_define

begin_define
define|#
directive|define
name|LBS_USETABSTOPS
value|0x80L
end_define

begin_define
define|#
directive|define
name|LBS_WANTKEYBOARDINPUT
value|0x400L
end_define

begin_define
define|#
directive|define
name|SBS_BOTTOMALIGN
value|0x4L
end_define

begin_define
define|#
directive|define
name|SBS_HORZ
value|0L
end_define

begin_define
define|#
directive|define
name|SBS_LEFTALIGN
value|0x2L
end_define

begin_define
define|#
directive|define
name|SBS_RIGHTALIGN
value|0x4L
end_define

begin_define
define|#
directive|define
name|SBS_SIZEBOX
value|0x8L
end_define

begin_define
define|#
directive|define
name|SBS_SIZEBOXBOTTOMRIGHTALIGN
value|0x4L
end_define

begin_define
define|#
directive|define
name|SBS_SIZEBOXTOPLEFTALIGN
value|0x2L
end_define

begin_define
define|#
directive|define
name|SBS_SIZEGRIP
value|0x10L
end_define

begin_define
define|#
directive|define
name|SBS_TOPALIGN
value|0x2L
end_define

begin_define
define|#
directive|define
name|SBS_VERT
value|0x1L
end_define

begin_define
define|#
directive|define
name|SS_BITMAP
value|0xeL
end_define

begin_define
define|#
directive|define
name|SS_BLACKFRAME
value|0x7L
end_define

begin_define
define|#
directive|define
name|SS_BLACKRECT
value|0x4L
end_define

begin_define
define|#
directive|define
name|SS_CENTER
value|0x1L
end_define

begin_define
define|#
directive|define
name|SS_CENTERIMAGE
value|0x200L
end_define

begin_define
define|#
directive|define
name|SS_ENHMETAFILE
value|0xfL
end_define

begin_define
define|#
directive|define
name|SS_ETCHEDFRAME
value|0x12L
end_define

begin_define
define|#
directive|define
name|SS_ETCHEDHORZ
value|0x10L
end_define

begin_define
define|#
directive|define
name|SS_ETCHEDVERT
value|0x11L
end_define

begin_define
define|#
directive|define
name|SS_GRAYFRAME
value|0x8L
end_define

begin_define
define|#
directive|define
name|SS_GRAYRECT
value|0x5L
end_define

begin_define
define|#
directive|define
name|SS_ICON
value|0x3L
end_define

begin_define
define|#
directive|define
name|SS_LEFT
value|0L
end_define

begin_define
define|#
directive|define
name|SS_LEFTNOWORDWRAP
value|0xcL
end_define

begin_define
define|#
directive|define
name|SS_NOPREFIX
value|0x80L
end_define

begin_define
define|#
directive|define
name|SS_NOTIFY
value|0x100L
end_define

begin_define
define|#
directive|define
name|SS_OWNERDRAW
value|0xdL
end_define

begin_define
define|#
directive|define
name|SS_REALSIZEIMAGE
value|0x800L
end_define

begin_define
define|#
directive|define
name|SS_RIGHT
value|0x2L
end_define

begin_define
define|#
directive|define
name|SS_RIGHTJUST
value|0x400L
end_define

begin_define
define|#
directive|define
name|SS_SIMPLE
value|0xbL
end_define

begin_define
define|#
directive|define
name|SS_SUNKEN
value|0x1000L
end_define

begin_define
define|#
directive|define
name|SS_USERITEM
value|0xaL
end_define

begin_define
define|#
directive|define
name|SS_WHITEFRAME
value|0x9L
end_define

begin_define
define|#
directive|define
name|SS_WHITERECT
value|0x6L
end_define

begin_define
define|#
directive|define
name|DS_3DLOOK
value|0x4L
end_define

begin_define
define|#
directive|define
name|DS_ABSALIGN
value|0x1L
end_define

begin_define
define|#
directive|define
name|DS_CENTER
value|0x800L
end_define

begin_define
define|#
directive|define
name|DS_CENTERMOUSE
value|0x1000L
end_define

begin_define
define|#
directive|define
name|DS_CONTEXTHELP
value|0x2000L
end_define

begin_define
define|#
directive|define
name|DS_CONTROL
value|0x400L
end_define

begin_define
define|#
directive|define
name|DS_FIXEDSYS
value|0x8L
end_define

begin_define
define|#
directive|define
name|DS_LOCALEDIT
value|0x20L
end_define

begin_define
define|#
directive|define
name|DS_MODALFRAME
value|0x80L
end_define

begin_define
define|#
directive|define
name|DS_NOFAILCREATE
value|0x10L
end_define

begin_define
define|#
directive|define
name|DS_NOIDLEMSG
value|0x100L
end_define

begin_define
define|#
directive|define
name|DS_SETFONT
value|0x40L
end_define

begin_define
define|#
directive|define
name|DS_SETFOREGROUND
value|0x200L
end_define

begin_define
define|#
directive|define
name|DS_SYSMODAL
value|0x2L
end_define

begin_comment
comment|/* A dialog control.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rc_dialog_control
block|{
comment|/* Next control.  */
name|struct
name|rc_dialog_control
modifier|*
name|next
decl_stmt|;
comment|/* ID.  */
name|rc_uint_type
name|id
decl_stmt|;
comment|/* Style.  */
name|rc_uint_type
name|style
decl_stmt|;
comment|/* Extended style.  */
name|rc_uint_type
name|exstyle
decl_stmt|;
comment|/* X coordinate.  */
name|rc_uint_type
name|x
decl_stmt|;
comment|/* Y coordinate.  */
name|rc_uint_type
name|y
decl_stmt|;
comment|/* Width.  */
name|rc_uint_type
name|width
decl_stmt|;
comment|/* Height.  */
name|rc_uint_type
name|height
decl_stmt|;
comment|/* Class name.  */
name|rc_res_id
name|class
decl_stmt|;
comment|/* Associated text.  */
name|rc_res_id
name|text
decl_stmt|;
comment|/* Extra data for the window procedure.  */
name|struct
name|rc_rcdata_item
modifier|*
name|data
decl_stmt|;
comment|/* Help ID.  Only used in an extended dialog.  */
name|rc_uint_type
name|help
decl_stmt|;
block|}
name|rc_dialog_control
typedef|;
end_typedef

begin_struct
struct|struct
name|__attribute__
argument_list|(
argument|(__packed__)
argument_list|)
name|bin_dialog_control
block|{
name|bfd_byte
name|style
index|[
literal|4
index|]
decl_stmt|;
name|bfd_byte
name|exstyle
index|[
literal|4
index|]
decl_stmt|;
name|bfd_byte
name|x
index|[
literal|2
index|]
decl_stmt|;
name|bfd_byte
name|y
index|[
literal|2
index|]
decl_stmt|;
name|bfd_byte
name|width
index|[
literal|2
index|]
decl_stmt|;
name|bfd_byte
name|height
index|[
literal|2
index|]
decl_stmt|;
name|bfd_byte
name|id
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BIN_DIALOG_CONTROL_SIZE
value|18
end_define

begin_struct
struct|struct
name|__attribute__
argument_list|(
argument|(__packed__)
argument_list|)
name|bin_dialogex_control
block|{
name|bfd_byte
name|help
index|[
literal|4
index|]
decl_stmt|;
name|bfd_byte
name|exstyle
index|[
literal|4
index|]
decl_stmt|;
name|bfd_byte
name|style
index|[
literal|4
index|]
decl_stmt|;
name|bfd_byte
name|x
index|[
literal|2
index|]
decl_stmt|;
name|bfd_byte
name|y
index|[
literal|2
index|]
decl_stmt|;
name|bfd_byte
name|width
index|[
literal|2
index|]
decl_stmt|;
name|bfd_byte
name|height
index|[
literal|2
index|]
decl_stmt|;
name|bfd_byte
name|id
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BIN_DIALOGEX_CONTROL_SIZE
value|24
end_define

begin_comment
comment|/* Control classes.  These can be used as the ID field in a rc_dialog_control.  */
end_comment

begin_define
define|#
directive|define
name|CTL_BUTTON
value|0x80
end_define

begin_define
define|#
directive|define
name|CTL_EDIT
value|0x81
end_define

begin_define
define|#
directive|define
name|CTL_STATIC
value|0x82
end_define

begin_define
define|#
directive|define
name|CTL_LISTBOX
value|0x83
end_define

begin_define
define|#
directive|define
name|CTL_SCROLLBAR
value|0x84
end_define

begin_define
define|#
directive|define
name|CTL_COMBOBOX
value|0x85
end_define

begin_comment
comment|/* A fontdir resource is a list of rc_fontdir.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rc_fontdir
block|{
name|struct
name|rc_fontdir
modifier|*
name|next
decl_stmt|;
comment|/* Index of font entry.  */
name|rc_uint_type
name|index
decl_stmt|;
comment|/* Length of font information.  */
name|rc_uint_type
name|length
decl_stmt|;
comment|/* Font information.  */
specifier|const
name|bfd_byte
modifier|*
name|data
decl_stmt|;
block|}
name|rc_fontdir
typedef|;
end_typedef

begin_struct
struct|struct
name|__attribute__
argument_list|(
argument|(__packed__)
argument_list|)
name|bin_fontdir_item
block|{
name|bfd_byte
name|index
index|[
literal|2
index|]
decl_stmt|;
name|bfd_byte
name|header
index|[
literal|54
index|]
decl_stmt|;
name|bfd_byte
name|device_name
index|[
literal|1
index|]
decl_stmt|;
comment|/* bfd_byte face_name[]; */
block|}
struct|;
end_struct

begin_comment
comment|/* A group_icon resource is a list of rc_group_icon.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rc_group_icon
block|{
comment|/* Next icon in group.  */
name|struct
name|rc_group_icon
modifier|*
name|next
decl_stmt|;
comment|/* Width.  */
name|bfd_byte
name|width
decl_stmt|;
comment|/* Height.  */
name|bfd_byte
name|height
decl_stmt|;
comment|/* Color count.  */
name|bfd_byte
name|colors
decl_stmt|;
comment|/* Planes.  */
name|rc_uint_type
name|planes
decl_stmt|;
comment|/* Bits per pixel.  */
name|rc_uint_type
name|bits
decl_stmt|;
comment|/* Number of bytes in cursor resource.  */
name|rc_uint_type
name|bytes
decl_stmt|;
comment|/* Index of cursor resource.  */
name|rc_uint_type
name|index
decl_stmt|;
block|}
name|rc_group_icon
typedef|;
end_typedef

begin_struct
struct|struct
name|__attribute__
argument_list|(
argument|(__packed__)
argument_list|)
name|bin_group_icon
block|{
name|bfd_byte
name|sig1
index|[
literal|2
index|]
decl_stmt|;
name|bfd_byte
name|sig2
index|[
literal|2
index|]
decl_stmt|;
name|bfd_byte
name|count
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BIN_GROUP_ICON_SIZE
value|6
end_define

begin_struct
struct|struct
name|__attribute__
argument_list|(
argument|(__packed__)
argument_list|)
name|bin_group_icon_item
block|{
name|bfd_byte
name|width
index|[
literal|1
index|]
decl_stmt|;
name|bfd_byte
name|height
index|[
literal|1
index|]
decl_stmt|;
name|bfd_byte
name|colors
index|[
literal|1
index|]
decl_stmt|;
name|bfd_byte
name|pad
index|[
literal|1
index|]
decl_stmt|;
name|bfd_byte
name|planes
index|[
literal|2
index|]
decl_stmt|;
name|bfd_byte
name|bits
index|[
literal|2
index|]
decl_stmt|;
name|bfd_byte
name|bytes
index|[
literal|4
index|]
decl_stmt|;
name|bfd_byte
name|index
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BIN_GROUP_ICON_ITEM_SIZE
value|14
end_define

begin_comment
comment|/* A menu resource.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rc_menu
block|{
comment|/* List of menuitems.  */
name|struct
name|rc_menuitem
modifier|*
name|items
decl_stmt|;
comment|/* Help ID.  I don't think there is any way to set this in an rc      file, but it can appear in the binary format.  */
name|rc_uint_type
name|help
decl_stmt|;
block|}
name|rc_menu
typedef|;
end_typedef

begin_struct
struct|struct
name|__attribute__
argument_list|(
argument|(__packed__)
argument_list|)
name|bin_menu
block|{
name|bfd_byte
name|sig1
index|[
literal|2
index|]
decl_stmt|;
name|bfd_byte
name|sig2
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BIN_MENU_SIZE
value|4
end_define

begin_struct
struct|struct
name|__attribute__
argument_list|(
argument|(__packed__)
argument_list|)
name|bin_menuex
block|{
name|bfd_byte
name|sig1
index|[
literal|2
index|]
decl_stmt|;
name|bfd_byte
name|sig2
index|[
literal|2
index|]
decl_stmt|;
name|bfd_byte
name|help
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BIN_MENUEX_SIZE
value|8
end_define

begin_comment
comment|/* A menu resource is a list of rc_menuitem.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rc_menuitem
block|{
comment|/* Next menu item.  */
name|struct
name|rc_menuitem
modifier|*
name|next
decl_stmt|;
comment|/* Type.  In a normal menu, rather than a menuex, this is the flags      field.  */
name|rc_uint_type
name|type
decl_stmt|;
comment|/* State.  This is only used in a menuex.  */
name|rc_uint_type
name|state
decl_stmt|;
comment|/* Id.  */
name|rc_uint_type
name|id
decl_stmt|;
comment|/* Unicode text.  */
name|unichar
modifier|*
name|text
decl_stmt|;
comment|/* Popup menu items for a popup.  */
name|struct
name|rc_menuitem
modifier|*
name|popup
decl_stmt|;
comment|/* Help ID.  This is only used in a menuex.  */
name|rc_uint_type
name|help
decl_stmt|;
block|}
name|rc_menuitem
typedef|;
end_typedef

begin_struct
struct|struct
name|__attribute__
argument_list|(
argument|(__packed__)
argument_list|)
name|bin_menuitem
block|{
name|bfd_byte
name|flags
index|[
literal|2
index|]
decl_stmt|;
name|bfd_byte
name|id
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BIN_MENUITEM_SIZE
value|4
end_define

begin_define
define|#
directive|define
name|BIN_MENUITEM_POPUP_SIZE
value|2
end_define

begin_struct
struct|struct
name|__attribute__
argument_list|(
argument|(__packed__)
argument_list|)
name|bin_menuitemex
block|{
name|bfd_byte
name|type
index|[
literal|4
index|]
decl_stmt|;
name|bfd_byte
name|state
index|[
literal|4
index|]
decl_stmt|;
name|bfd_byte
name|id
index|[
literal|4
index|]
decl_stmt|;
name|bfd_byte
name|flags
index|[
literal|2
index|]
decl_stmt|;
comment|/* unicode text */
comment|/* if popup: align, bfd_byte help[4], align, bin_menuitemex[]; */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BIN_MENUITEMEX_SIZE
value|14
end_define

begin_comment
comment|/* Menu item flags.  These can appear in the flags field of a rc_menuitem.  */
end_comment

begin_define
define|#
directive|define
name|MENUITEM_GRAYED
value|0x001
end_define

begin_define
define|#
directive|define
name|MENUITEM_INACTIVE
value|0x002
end_define

begin_define
define|#
directive|define
name|MENUITEM_BITMAP
value|0x004
end_define

begin_define
define|#
directive|define
name|MENUITEM_OWNERDRAW
value|0x100
end_define

begin_define
define|#
directive|define
name|MENUITEM_CHECKED
value|0x008
end_define

begin_define
define|#
directive|define
name|MENUITEM_POPUP
value|0x010
end_define

begin_define
define|#
directive|define
name|MENUITEM_MENUBARBREAK
value|0x020
end_define

begin_define
define|#
directive|define
name|MENUITEM_MENUBREAK
value|0x040
end_define

begin_define
define|#
directive|define
name|MENUITEM_ENDMENU
value|0x080
end_define

begin_define
define|#
directive|define
name|MENUITEM_HELP
value|0x4000
end_define

begin_comment
comment|/* An rcdata resource is a pointer to a list of rc_rcdata_item.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rc_rcdata_item
block|{
comment|/* Next data item.  */
name|struct
name|rc_rcdata_item
modifier|*
name|next
decl_stmt|;
comment|/* Type of data.  */
enum|enum
block|{
name|RCDATA_WORD
block|,
name|RCDATA_DWORD
block|,
name|RCDATA_STRING
block|,
name|RCDATA_WSTRING
block|,
name|RCDATA_BUFFER
block|}
name|type
enum|;
union|union
block|{
name|rc_uint_type
name|word
decl_stmt|;
name|rc_uint_type
name|dword
decl_stmt|;
struct|struct
block|{
name|rc_uint_type
name|length
decl_stmt|;
specifier|const
name|char
modifier|*
name|s
decl_stmt|;
block|}
name|string
struct|;
struct|struct
block|{
name|rc_uint_type
name|length
decl_stmt|;
specifier|const
name|unichar
modifier|*
name|w
decl_stmt|;
block|}
name|wstring
struct|;
struct|struct
block|{
name|rc_uint_type
name|length
decl_stmt|;
specifier|const
name|bfd_byte
modifier|*
name|data
decl_stmt|;
block|}
name|buffer
struct|;
block|}
name|u
union|;
block|}
name|rc_rcdata_item
typedef|;
end_typedef

begin_comment
comment|/* A stringtable resource is a pointer to a rc_stringtable.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rc_stringtable
block|{
comment|/* Each stringtable resource is a list of 16 unicode strings.  */
struct|struct
block|{
comment|/* Length of string.  */
name|rc_uint_type
name|length
decl_stmt|;
comment|/* String data if length> 0.  */
name|unichar
modifier|*
name|string
decl_stmt|;
block|}
name|strings
index|[
literal|16
index|]
struct|;
block|}
name|rc_stringtable
typedef|;
end_typedef

begin_comment
comment|/* A versioninfo resource points to a rc_versioninfo.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rc_versioninfo
block|{
comment|/* Fixed version information.  */
name|struct
name|rc_fixed_versioninfo
modifier|*
name|fixed
decl_stmt|;
comment|/* Variable version information.  */
name|struct
name|rc_ver_info
modifier|*
name|var
decl_stmt|;
block|}
name|rc_versioninfo
typedef|;
end_typedef

begin_struct
struct|struct
name|__attribute__
argument_list|(
argument|(__packed__)
argument_list|)
name|bin_versioninfo
block|{
name|bfd_byte
name|size
index|[
literal|2
index|]
decl_stmt|;
name|bfd_byte
name|fixed_size
index|[
literal|2
index|]
decl_stmt|;
name|bfd_byte
name|sig2
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BIN_VERSIONINFO_SIZE
value|6
end_define

begin_comment
comment|/* The fixed portion of a versioninfo resource.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rc_fixed_versioninfo
block|{
comment|/* The file version, which is two 32 bit integers.  */
name|rc_uint_type
name|file_version_ms
decl_stmt|;
name|rc_uint_type
name|file_version_ls
decl_stmt|;
comment|/* The product version, which is two 32 bit integers.  */
name|rc_uint_type
name|product_version_ms
decl_stmt|;
name|rc_uint_type
name|product_version_ls
decl_stmt|;
comment|/* The file flags mask.  */
name|rc_uint_type
name|file_flags_mask
decl_stmt|;
comment|/* The file flags.  */
name|rc_uint_type
name|file_flags
decl_stmt|;
comment|/* The OS type.  */
name|rc_uint_type
name|file_os
decl_stmt|;
comment|/* The file type.  */
name|rc_uint_type
name|file_type
decl_stmt|;
comment|/* The file subtype.  */
name|rc_uint_type
name|file_subtype
decl_stmt|;
comment|/* The date, which in Windows is two 32 bit integers.  */
name|rc_uint_type
name|file_date_ms
decl_stmt|;
name|rc_uint_type
name|file_date_ls
decl_stmt|;
block|}
name|rc_fixed_versioninfo
typedef|;
end_typedef

begin_struct
struct|struct
name|__attribute__
argument_list|(
argument|(__packed__)
argument_list|)
name|bin_fixed_versioninfo
block|{
name|bfd_byte
name|sig1
index|[
literal|4
index|]
decl_stmt|;
name|bfd_byte
name|sig2
index|[
literal|4
index|]
decl_stmt|;
name|bfd_byte
name|file_version
index|[
literal|4
index|]
decl_stmt|;
name|bfd_byte
name|file_version_ls
index|[
literal|4
index|]
decl_stmt|;
name|bfd_byte
name|product_version_ms
index|[
literal|4
index|]
decl_stmt|;
name|bfd_byte
name|product_version_ls
index|[
literal|4
index|]
decl_stmt|;
name|bfd_byte
name|file_flags_mask
index|[
literal|4
index|]
decl_stmt|;
name|bfd_byte
name|file_flags
index|[
literal|4
index|]
decl_stmt|;
name|bfd_byte
name|file_os
index|[
literal|4
index|]
decl_stmt|;
name|bfd_byte
name|file_type
index|[
literal|4
index|]
decl_stmt|;
name|bfd_byte
name|file_subtype
index|[
literal|4
index|]
decl_stmt|;
name|bfd_byte
name|file_date_ms
index|[
literal|4
index|]
decl_stmt|;
name|bfd_byte
name|file_date_ls
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BIN_FIXED_VERSIONINFO_SIZE
value|52
end_define

begin_comment
comment|/* A list of variable version information.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rc_ver_info
block|{
comment|/* Next item.  */
name|struct
name|rc_ver_info
modifier|*
name|next
decl_stmt|;
comment|/* Type of data.  */
enum|enum
block|{
name|VERINFO_STRING
block|,
name|VERINFO_VAR
block|}
name|type
enum|;
union|union
block|{
comment|/* StringFileInfo data.  */
struct|struct
block|{
comment|/* Language.  */
name|unichar
modifier|*
name|language
decl_stmt|;
comment|/* Strings.  */
name|struct
name|rc_ver_stringinfo
modifier|*
name|strings
decl_stmt|;
block|}
name|string
struct|;
comment|/* VarFileInfo data.  */
struct|struct
block|{
comment|/* Key.  */
name|unichar
modifier|*
name|key
decl_stmt|;
comment|/* Values.  */
name|struct
name|rc_ver_varinfo
modifier|*
name|var
decl_stmt|;
block|}
name|var
struct|;
block|}
name|u
union|;
block|}
name|rc_ver_info
typedef|;
end_typedef

begin_struct
struct|struct
name|__attribute__
argument_list|(
argument|(__packed__)
argument_list|)
name|bin_ver_info
block|{
name|bfd_byte
name|size
index|[
literal|2
index|]
decl_stmt|;
name|bfd_byte
name|sig1
index|[
literal|2
index|]
decl_stmt|;
name|bfd_byte
name|sig2
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BIN_VER_INFO_SIZE
value|6
end_define

begin_comment
comment|/* A list of string version information.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rc_ver_stringinfo
block|{
comment|/* Next string.  */
name|struct
name|rc_ver_stringinfo
modifier|*
name|next
decl_stmt|;
comment|/* Key.  */
name|unichar
modifier|*
name|key
decl_stmt|;
comment|/* Value.  */
name|unichar
modifier|*
name|value
decl_stmt|;
block|}
name|rc_ver_stringinfo
typedef|;
end_typedef

begin_comment
comment|/* A list of variable version information.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rc_ver_varinfo
block|{
comment|/* Next item.  */
name|struct
name|rc_ver_varinfo
modifier|*
name|next
decl_stmt|;
comment|/* Language ID.  */
name|rc_uint_type
name|language
decl_stmt|;
comment|/* Character set ID.  */
name|rc_uint_type
name|charset
decl_stmt|;
block|}
name|rc_ver_varinfo
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|rc_toolbar_item
block|{
name|struct
name|rc_toolbar_item
modifier|*
name|next
decl_stmt|;
name|struct
name|rc_toolbar_item
modifier|*
name|prev
decl_stmt|;
name|rc_res_id
name|id
decl_stmt|;
block|}
name|rc_toolbar_item
typedef|;
end_typedef

begin_struct
struct|struct
name|__attribute__
argument_list|(
argument|(__packed__)
argument_list|)
name|bin_messagetable_item
block|{
name|bfd_byte
name|length
index|[
literal|2
index|]
decl_stmt|;
name|bfd_byte
name|flags
index|[
literal|2
index|]
decl_stmt|;
name|bfd_byte
name|data
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BIN_MESSAGETABLE_ITEM_SIZE
value|4
end_define

begin_define
define|#
directive|define
name|MESSAGE_RESOURCE_UNICODE
value|0x0001
end_define

begin_struct
struct|struct
name|__attribute__
argument_list|(
argument|(__packed__)
argument_list|)
name|bin_messagetable_block
block|{
name|bfd_byte
name|lowid
index|[
literal|4
index|]
decl_stmt|;
name|bfd_byte
name|highid
index|[
literal|4
index|]
decl_stmt|;
name|bfd_byte
name|offset
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BIN_MESSAGETABLE_BLOCK_SIZE
value|12
end_define

begin_struct
struct|struct
name|__attribute__
argument_list|(
argument|(__packed__)
argument_list|)
name|bin_messagetable
block|{
name|bfd_byte
name|cblocks
index|[
literal|4
index|]
decl_stmt|;
name|struct
name|bin_messagetable_block
name|items
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BIN_MESSAGETABLE_SIZE
value|8
end_define

begin_typedef
typedef|typedef
struct|struct
name|rc_toolbar
block|{
name|rc_uint_type
name|button_width
decl_stmt|;
name|rc_uint_type
name|button_height
decl_stmt|;
name|rc_uint_type
name|nitems
decl_stmt|;
name|rc_toolbar_item
modifier|*
name|items
decl_stmt|;
block|}
name|rc_toolbar
typedef|;
end_typedef

begin_struct
struct|struct
name|__attribute__
argument_list|(
argument|(__packed__)
argument_list|)
name|bin_toolbar
block|{
name|bfd_byte
name|button_width
index|[
literal|4
index|]
decl_stmt|;
name|bfd_byte
name|button_height
index|[
literal|4
index|]
decl_stmt|;
name|bfd_byte
name|nitems
index|[
literal|4
index|]
decl_stmt|;
comment|/* { bfd_byte id[4]; } * nitems; */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BIN_TOOLBAR_SIZE
value|12
end_define

begin_decl_stmt
specifier|extern
name|int
name|target_is_bigendian
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
struct|struct
name|windres_bfd
block|{
name|bfd
modifier|*
name|abfd
decl_stmt|;
name|asection
modifier|*
name|sec
decl_stmt|;
name|rc_uint_type
name|kind
range|:
literal|4
decl_stmt|;
block|}
name|windres_bfd
typedef|;
end_typedef

begin_define
define|#
directive|define
name|WR_KIND_TARGET
value|0
end_define

begin_define
define|#
directive|define
name|WR_KIND_BFD
value|1
end_define

begin_define
define|#
directive|define
name|WR_KIND_BFD_BIN_L
value|2
end_define

begin_define
define|#
directive|define
name|WR_KIND_BFD_BIN_B
value|3
end_define

begin_define
define|#
directive|define
name|WR_KIND
parameter_list|(
name|PTR
parameter_list|)
value|(PTR)->kind
end_define

begin_define
define|#
directive|define
name|WR_SECTION
parameter_list|(
name|PTR
parameter_list|)
value|(PTR)->sec
end_define

begin_define
define|#
directive|define
name|WR_BFD
parameter_list|(
name|PTR
parameter_list|)
value|(PTR)->abfd
end_define

begin_function_decl
specifier|extern
name|void
name|set_windres_bfd_content
parameter_list|(
name|windres_bfd
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|rc_uint_type
parameter_list|,
name|rc_uint_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|get_windres_bfd_content
parameter_list|(
name|windres_bfd
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|rc_uint_type
parameter_list|,
name|rc_uint_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|windres_put_8
parameter_list|(
name|windres_bfd
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|rc_uint_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|windres_put_16
parameter_list|(
name|windres_bfd
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|rc_uint_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|windres_put_32
parameter_list|(
name|windres_bfd
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|rc_uint_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rc_uint_type
name|windres_get_8
parameter_list|(
name|windres_bfd
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|rc_uint_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rc_uint_type
name|windres_get_16
parameter_list|(
name|windres_bfd
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|rc_uint_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rc_uint_type
name|windres_get_32
parameter_list|(
name|windres_bfd
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|rc_uint_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_windres_bfd
parameter_list|(
name|windres_bfd
modifier|*
parameter_list|,
name|bfd
modifier|*
parameter_list|,
name|asection
modifier|*
parameter_list|,
name|rc_uint_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_windres_bfd_endianess
parameter_list|(
name|windres_bfd
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

