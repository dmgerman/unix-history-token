begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* windres.h -- header file for windres program.    Copyright 1997, 1998, 2000, 2002, 2003 Free Software Foundation, Inc.    Written by Ian Lance Taylor, Cygnus Support.     This file is part of GNU Binutils.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"ansidecl.h"
end_include

begin_comment
comment|/* This is the header file for the windres program.  It defines    structures and declares functions used within the program.  */
end_comment

begin_include
include|#
directive|include
file|"winduni.h"
end_include

begin_comment
comment|/* We represent resources internally as a tree, similar to the tree    used in the .rsrc section of a COFF file.  The root is a    res_directory structure.  */
end_comment

begin_struct
struct|struct
name|res_directory
block|{
comment|/* Resource flags.  According to the MS docs, this is currently      always zero.  */
name|unsigned
name|long
name|characteristics
decl_stmt|;
comment|/* Time/date stamp.  */
name|unsigned
name|long
name|time
decl_stmt|;
comment|/* Major version number.  */
name|unsigned
name|short
name|major
decl_stmt|;
comment|/* Minor version number.  */
name|unsigned
name|short
name|minor
decl_stmt|;
comment|/* Directory entries.  */
name|struct
name|res_entry
modifier|*
name|entries
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* A resource ID is stored in a res_id structure.  */
end_comment

begin_struct
struct|struct
name|res_id
block|{
comment|/* Non-zero if this entry has a name rather than an ID.  */
name|unsigned
name|int
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
name|int
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
name|unsigned
name|long
name|id
decl_stmt|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_comment
comment|/* Each entry in the tree is a res_entry structure.  We mix    directories and resources because in a COFF file all entries in a    directory are sorted together, whether the entries are    subdirectories or resources.  */
end_comment

begin_struct
struct|struct
name|res_entry
block|{
comment|/* Next entry.  */
name|struct
name|res_entry
modifier|*
name|next
decl_stmt|;
comment|/* Resource ID.  */
name|struct
name|res_id
name|id
decl_stmt|;
comment|/* Non-zero if this entry is a subdirectory rather than a leaf.  */
name|unsigned
name|int
name|subdir
range|:
literal|1
decl_stmt|;
union|union
block|{
comment|/* If the subdir field is non-zero, this is a pointer to the        subdirectory.  */
name|struct
name|res_directory
modifier|*
name|dir
decl_stmt|;
comment|/* If the subdir field is zero, this is a pointer to the resource        data.  */
name|struct
name|res_resource
modifier|*
name|res
decl_stmt|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_comment
comment|/* Types of resources.  */
end_comment

begin_enum
enum|enum
name|res_type
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
block|}
enum|;
end_enum

begin_comment
comment|/* A res file and a COFF file store information differently.  The    res_info structures holds data which in a res file is stored with    each resource, but in a COFF file is stored elsewhere.  */
end_comment

begin_struct
struct|struct
name|res_res_info
block|{
comment|/* Language.  In a COFF file, the third level of the directory is      keyed by the language, so the language of a resource is defined      by its location in the resource tree.  */
name|unsigned
name|short
name|language
decl_stmt|;
comment|/* Characteristics of the resource.  Entirely user defined.  In a      COFF file, the res_directory structure has a characteristics      field, but I don't know if it's related to the one in the res      file.  */
name|unsigned
name|long
name|characteristics
decl_stmt|;
comment|/* Version of the resource.  Entirely user defined.  In a COFF file,      the res_directory structure has a characteristics field, but I      don't know if it's related to the one in the res file.  */
name|unsigned
name|long
name|version
decl_stmt|;
comment|/* Memory flags.  This is a combination of the MEMFLAG values      defined below.  Most of these values are historical, and are not      meaningful for win32.  I don't think there is any way to store      this information in a COFF file.  */
name|unsigned
name|short
name|memflags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Each resource in a COFF file has some information which can does    not appear in a res file.  */
end_comment

begin_struct
struct|struct
name|res_coff_info
block|{
comment|/* The code page used for the data.  I don't really know what this      should be.  */
name|unsigned
name|long
name|codepage
decl_stmt|;
comment|/* A resource entry in a COFF file has a reserved field, which we      record here when reading a COFF file.  When writing a COFF file,      we set this field to zero.  */
name|unsigned
name|long
name|reserved
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Resource data is stored in a res_resource structure.  */
end_comment

begin_struct
struct|struct
name|res_resource
block|{
comment|/* The type of resource.  */
name|enum
name|res_type
name|type
decl_stmt|;
comment|/* The data for the resource.  */
union|union
block|{
struct|struct
block|{
name|unsigned
name|long
name|length
decl_stmt|;
specifier|const
name|unsigned
name|char
modifier|*
name|data
decl_stmt|;
block|}
name|data
struct|;
name|struct
name|accelerator
modifier|*
name|acc
decl_stmt|;
name|struct
name|cursor
modifier|*
name|cursor
decl_stmt|;
name|struct
name|group_cursor
modifier|*
name|group_cursor
decl_stmt|;
name|struct
name|dialog
modifier|*
name|dialog
decl_stmt|;
name|struct
name|fontdir
modifier|*
name|fontdir
decl_stmt|;
name|struct
name|group_icon
modifier|*
name|group_icon
decl_stmt|;
name|struct
name|menu
modifier|*
name|menu
decl_stmt|;
name|struct
name|rcdata_item
modifier|*
name|rcdata
decl_stmt|;
name|struct
name|stringtable
modifier|*
name|stringtable
decl_stmt|;
name|struct
name|rcdata_item
modifier|*
name|userdata
decl_stmt|;
name|struct
name|versioninfo
modifier|*
name|versioninfo
decl_stmt|;
block|}
name|u
union|;
comment|/* Information from a res file.  */
name|struct
name|res_res_info
name|res_info
decl_stmt|;
comment|/* Information from a COFF file.  */
name|struct
name|res_coff_info
name|coff_info
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SUBLANG_SHIFT
value|10
end_define

begin_comment
comment|/* Memory flags in the memflags field of a struct res_resource.  */
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
comment|/* Standard resource type codes.  These are used in the ID field of a    res_entry structure.  */
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

begin_comment
comment|/* An accelerator resource is a linked list of these structures.  */
end_comment

begin_struct
struct|struct
name|accelerator
block|{
comment|/* Next accelerator.  */
name|struct
name|accelerator
modifier|*
name|next
decl_stmt|;
comment|/* Flags.  A combination of the ACC values defined below.  */
name|unsigned
name|short
name|flags
decl_stmt|;
comment|/* Key value.  */
name|unsigned
name|short
name|key
decl_stmt|;
comment|/* Resource ID.  */
name|unsigned
name|short
name|id
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Accelerator flags in the flags field of a struct accelerator.    These are the same values that appear in a res file.  I hope.  */
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

begin_struct
struct|struct
name|cursor
block|{
comment|/* X coordinate of hotspot.  */
name|short
name|xhotspot
decl_stmt|;
comment|/* Y coordinate of hotspot.  */
name|short
name|yhotspot
decl_stmt|;
comment|/* Length of bitmap data.  */
name|unsigned
name|long
name|length
decl_stmt|;
comment|/* Data.  */
specifier|const
name|unsigned
name|char
modifier|*
name|data
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* A group_cursor resource is a list of group_cursor structures.  */
end_comment

begin_struct
struct|struct
name|group_cursor
block|{
comment|/* Next cursor in group.  */
name|struct
name|group_cursor
modifier|*
name|next
decl_stmt|;
comment|/* Width.  */
name|unsigned
name|short
name|width
decl_stmt|;
comment|/* Height.  */
name|unsigned
name|short
name|height
decl_stmt|;
comment|/* Planes.  */
name|unsigned
name|short
name|planes
decl_stmt|;
comment|/* Bits per pixel.  */
name|unsigned
name|short
name|bits
decl_stmt|;
comment|/* Number of bytes in cursor resource.  */
name|unsigned
name|long
name|bytes
decl_stmt|;
comment|/* Index of cursor resource.  */
name|unsigned
name|short
name|index
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* A dialog resource.  */
end_comment

begin_struct
struct|struct
name|dialog
block|{
comment|/* Basic window style.  */
name|unsigned
name|long
name|style
decl_stmt|;
comment|/* Extended window style.  */
name|unsigned
name|long
name|exstyle
decl_stmt|;
comment|/* X coordinate.  */
name|unsigned
name|short
name|x
decl_stmt|;
comment|/* Y coordinate.  */
name|unsigned
name|short
name|y
decl_stmt|;
comment|/* Width.  */
name|unsigned
name|short
name|width
decl_stmt|;
comment|/* Height.  */
name|unsigned
name|short
name|height
decl_stmt|;
comment|/* Menu name.  */
name|struct
name|res_id
name|menu
decl_stmt|;
comment|/* Class name.  */
name|struct
name|res_id
name|class
decl_stmt|;
comment|/* Caption.  */
name|unichar
modifier|*
name|caption
decl_stmt|;
comment|/* Font point size.  */
name|unsigned
name|short
name|pointsize
decl_stmt|;
comment|/* Font name.  */
name|unichar
modifier|*
name|font
decl_stmt|;
comment|/* Extended information for a dialogex.  */
name|struct
name|dialog_ex
modifier|*
name|ex
decl_stmt|;
comment|/* Controls.  */
name|struct
name|dialog_control
modifier|*
name|controls
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* An extended dialog has additional information.  */
end_comment

begin_struct
struct|struct
name|dialog_ex
block|{
comment|/* Help ID.  */
name|unsigned
name|long
name|help
decl_stmt|;
comment|/* Font weight.  */
name|unsigned
name|short
name|weight
decl_stmt|;
comment|/* Whether the font is italic.  */
name|unsigned
name|char
name|italic
decl_stmt|;
comment|/* Character set.  */
name|unsigned
name|char
name|charset
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Window style flags, from the winsup Defines.h header file.  These    can appear in the style field of a struct dialog or a struct    dialog_control.  */
end_comment

begin_define
define|#
directive|define
name|CW_USEDEFAULT
value|(0x80000000)
end_define

begin_define
define|#
directive|define
name|WS_BORDER
value|(0x800000L)
end_define

begin_define
define|#
directive|define
name|WS_CAPTION
value|(0xc00000L)
end_define

begin_define
define|#
directive|define
name|WS_CHILD
value|(0x40000000L)
end_define

begin_define
define|#
directive|define
name|WS_CHILDWINDOW
value|(0x40000000L)
end_define

begin_define
define|#
directive|define
name|WS_CLIPCHILDREN
value|(0x2000000L)
end_define

begin_define
define|#
directive|define
name|WS_CLIPSIBLINGS
value|(0x4000000L)
end_define

begin_define
define|#
directive|define
name|WS_DISABLED
value|(0x8000000L)
end_define

begin_define
define|#
directive|define
name|WS_DLGFRAME
value|(0x400000L)
end_define

begin_define
define|#
directive|define
name|WS_GROUP
value|(0x20000L)
end_define

begin_define
define|#
directive|define
name|WS_HSCROLL
value|(0x100000L)
end_define

begin_define
define|#
directive|define
name|WS_ICONIC
value|(0x20000000L)
end_define

begin_define
define|#
directive|define
name|WS_MAXIMIZE
value|(0x1000000L)
end_define

begin_define
define|#
directive|define
name|WS_MAXIMIZEBOX
value|(0x10000L)
end_define

begin_define
define|#
directive|define
name|WS_MINIMIZE
value|(0x20000000L)
end_define

begin_define
define|#
directive|define
name|WS_MINIMIZEBOX
value|(0x20000L)
end_define

begin_define
define|#
directive|define
name|WS_OVERLAPPED
value|(0L)
end_define

begin_define
define|#
directive|define
name|WS_OVERLAPPEDWINDOW
value|(0xcf0000L)
end_define

begin_define
define|#
directive|define
name|WS_POPUP
value|(0x80000000L)
end_define

begin_define
define|#
directive|define
name|WS_POPUPWINDOW
value|(0x80880000L)
end_define

begin_define
define|#
directive|define
name|WS_SIZEBOX
value|(0x40000L)
end_define

begin_define
define|#
directive|define
name|WS_SYSMENU
value|(0x80000L)
end_define

begin_define
define|#
directive|define
name|WS_TABSTOP
value|(0x10000L)
end_define

begin_define
define|#
directive|define
name|WS_THICKFRAME
value|(0x40000L)
end_define

begin_define
define|#
directive|define
name|WS_TILED
value|(0L)
end_define

begin_define
define|#
directive|define
name|WS_TILEDWINDOW
value|(0xcf0000L)
end_define

begin_define
define|#
directive|define
name|WS_VISIBLE
value|(0x10000000L)
end_define

begin_define
define|#
directive|define
name|WS_VSCROLL
value|(0x200000L)
end_define

begin_define
define|#
directive|define
name|MDIS_ALLCHILDSTYLES
value|(0x1)
end_define

begin_define
define|#
directive|define
name|BS_3STATE
value|(0x5L)
end_define

begin_define
define|#
directive|define
name|BS_AUTO3STATE
value|(0x6L)
end_define

begin_define
define|#
directive|define
name|BS_AUTOCHECKBOX
value|(0x3L)
end_define

begin_define
define|#
directive|define
name|BS_AUTORADIOBUTTON
value|(0x9L)
end_define

begin_define
define|#
directive|define
name|BS_BITMAP
value|(0x80L)
end_define

begin_define
define|#
directive|define
name|BS_BOTTOM
value|(0x800L)
end_define

begin_define
define|#
directive|define
name|BS_CENTER
value|(0x300L)
end_define

begin_define
define|#
directive|define
name|BS_CHECKBOX
value|(0x2L)
end_define

begin_define
define|#
directive|define
name|BS_DEFPUSHBUTTON
value|(0x1L)
end_define

begin_define
define|#
directive|define
name|BS_GROUPBOX
value|(0x7L)
end_define

begin_define
define|#
directive|define
name|BS_ICON
value|(0x40L)
end_define

begin_define
define|#
directive|define
name|BS_LEFT
value|(0x100L)
end_define

begin_define
define|#
directive|define
name|BS_LEFTTEXT
value|(0x20L)
end_define

begin_define
define|#
directive|define
name|BS_MULTILINE
value|(0x2000L)
end_define

begin_define
define|#
directive|define
name|BS_NOTIFY
value|(0x4000L)
end_define

begin_define
define|#
directive|define
name|BS_OWNERDRAW
value|(0xbL)
end_define

begin_define
define|#
directive|define
name|BS_PUSHBOX
value|(0xcL)
end_define

begin_comment
comment|/* FIXME!  What should this be?  */
end_comment

begin_define
define|#
directive|define
name|BS_PUSHBUTTON
value|(0L)
end_define

begin_define
define|#
directive|define
name|BS_PUSHLIKE
value|(0x1000L)
end_define

begin_define
define|#
directive|define
name|BS_RADIOBUTTON
value|(0x4L)
end_define

begin_define
define|#
directive|define
name|BS_RIGHT
value|(0x200L)
end_define

begin_define
define|#
directive|define
name|BS_RIGHTBUTTON
value|(0x20L)
end_define

begin_define
define|#
directive|define
name|BS_TEXT
value|(0L)
end_define

begin_define
define|#
directive|define
name|BS_TOP
value|(0x400L)
end_define

begin_define
define|#
directive|define
name|BS_USERBUTTON
value|(0x8L)
end_define

begin_define
define|#
directive|define
name|BS_VCENTER
value|(0xc00L)
end_define

begin_define
define|#
directive|define
name|CBS_AUTOHSCROLL
value|(0x40L)
end_define

begin_define
define|#
directive|define
name|CBS_DISABLENOSCROLL
value|(0x800L)
end_define

begin_define
define|#
directive|define
name|CBS_DROPDOWN
value|(0x2L)
end_define

begin_define
define|#
directive|define
name|CBS_DROPDOWNLIST
value|(0x3L)
end_define

begin_define
define|#
directive|define
name|CBS_HASSTRINGS
value|(0x200L)
end_define

begin_define
define|#
directive|define
name|CBS_LOWERCASE
value|(0x4000L)
end_define

begin_define
define|#
directive|define
name|CBS_NOINTEGRALHEIGHT
value|(0x400L)
end_define

begin_define
define|#
directive|define
name|CBS_OEMCONVERT
value|(0x80L)
end_define

begin_define
define|#
directive|define
name|CBS_OWNERDRAWFIXED
value|(0x10L)
end_define

begin_define
define|#
directive|define
name|CBS_OWNERDRAWVARIABLE
value|(0x20L)
end_define

begin_define
define|#
directive|define
name|CBS_SIMPLE
value|(0x1L)
end_define

begin_define
define|#
directive|define
name|CBS_SORT
value|(0x100L)
end_define

begin_define
define|#
directive|define
name|CBS_UPPERCASE
value|(0x2000L)
end_define

begin_define
define|#
directive|define
name|ES_AUTOHSCROLL
value|(0x80L)
end_define

begin_define
define|#
directive|define
name|ES_AUTOVSCROLL
value|(0x40L)
end_define

begin_define
define|#
directive|define
name|ES_CENTER
value|(0x1L)
end_define

begin_define
define|#
directive|define
name|ES_LEFT
value|(0L)
end_define

begin_define
define|#
directive|define
name|ES_LOWERCASE
value|(0x10L)
end_define

begin_define
define|#
directive|define
name|ES_MULTILINE
value|(0x4L)
end_define

begin_define
define|#
directive|define
name|ES_NOHIDESEL
value|(0x100L)
end_define

begin_define
define|#
directive|define
name|ES_NUMBER
value|(0x2000L)
end_define

begin_define
define|#
directive|define
name|ES_OEMCONVERT
value|(0x400L)
end_define

begin_define
define|#
directive|define
name|ES_PASSWORD
value|(0x20L)
end_define

begin_define
define|#
directive|define
name|ES_READONLY
value|(0x800L)
end_define

begin_define
define|#
directive|define
name|ES_RIGHT
value|(0x2L)
end_define

begin_define
define|#
directive|define
name|ES_UPPERCASE
value|(0x8L)
end_define

begin_define
define|#
directive|define
name|ES_WANTRETURN
value|(0x1000L)
end_define

begin_define
define|#
directive|define
name|LBS_DISABLENOSCROLL
value|(0x1000L)
end_define

begin_define
define|#
directive|define
name|LBS_EXTENDEDSEL
value|(0x800L)
end_define

begin_define
define|#
directive|define
name|LBS_HASSTRINGS
value|(0x40L)
end_define

begin_define
define|#
directive|define
name|LBS_MULTICOLUMN
value|(0x200L)
end_define

begin_define
define|#
directive|define
name|LBS_MULTIPLESEL
value|(0x8L)
end_define

begin_define
define|#
directive|define
name|LBS_NODATA
value|(0x2000L)
end_define

begin_define
define|#
directive|define
name|LBS_NOINTEGRALHEIGHT
value|(0x100L)
end_define

begin_define
define|#
directive|define
name|LBS_NOREDRAW
value|(0x4L)
end_define

begin_define
define|#
directive|define
name|LBS_NOSEL
value|(0x4000L)
end_define

begin_define
define|#
directive|define
name|LBS_NOTIFY
value|(0x1L)
end_define

begin_define
define|#
directive|define
name|LBS_OWNERDRAWFIXED
value|(0x10L)
end_define

begin_define
define|#
directive|define
name|LBS_OWNERDRAWVARIABLE
value|(0x20L)
end_define

begin_define
define|#
directive|define
name|LBS_SORT
value|(0x2L)
end_define

begin_define
define|#
directive|define
name|LBS_STANDARD
value|(0xa00003L)
end_define

begin_define
define|#
directive|define
name|LBS_USETABSTOPS
value|(0x80L)
end_define

begin_define
define|#
directive|define
name|LBS_WANTKEYBOARDINPUT
value|(0x400L)
end_define

begin_define
define|#
directive|define
name|SBS_BOTTOMALIGN
value|(0x4L)
end_define

begin_define
define|#
directive|define
name|SBS_HORZ
value|(0L)
end_define

begin_define
define|#
directive|define
name|SBS_LEFTALIGN
value|(0x2L)
end_define

begin_define
define|#
directive|define
name|SBS_RIGHTALIGN
value|(0x4L)
end_define

begin_define
define|#
directive|define
name|SBS_SIZEBOX
value|(0x8L)
end_define

begin_define
define|#
directive|define
name|SBS_SIZEBOXBOTTOMRIGHTALIGN
value|(0x4L)
end_define

begin_define
define|#
directive|define
name|SBS_SIZEBOXTOPLEFTALIGN
value|(0x2L)
end_define

begin_define
define|#
directive|define
name|SBS_SIZEGRIP
value|(0x10L)
end_define

begin_define
define|#
directive|define
name|SBS_TOPALIGN
value|(0x2L)
end_define

begin_define
define|#
directive|define
name|SBS_VERT
value|(0x1L)
end_define

begin_define
define|#
directive|define
name|SS_BITMAP
value|(0xeL)
end_define

begin_define
define|#
directive|define
name|SS_BLACKFRAME
value|(0x7L)
end_define

begin_define
define|#
directive|define
name|SS_BLACKRECT
value|(0x4L)
end_define

begin_define
define|#
directive|define
name|SS_CENTER
value|(0x1L)
end_define

begin_define
define|#
directive|define
name|SS_CENTERIMAGE
value|(0x200L)
end_define

begin_define
define|#
directive|define
name|SS_ENHMETAFILE
value|(0xfL)
end_define

begin_define
define|#
directive|define
name|SS_ETCHEDFRAME
value|(0x12L)
end_define

begin_define
define|#
directive|define
name|SS_ETCHEDHORZ
value|(0x10L)
end_define

begin_define
define|#
directive|define
name|SS_ETCHEDVERT
value|(0x11L)
end_define

begin_define
define|#
directive|define
name|SS_GRAYFRAME
value|(0x8L)
end_define

begin_define
define|#
directive|define
name|SS_GRAYRECT
value|(0x5L)
end_define

begin_define
define|#
directive|define
name|SS_ICON
value|(0x3L)
end_define

begin_define
define|#
directive|define
name|SS_LEFT
value|(0L)
end_define

begin_define
define|#
directive|define
name|SS_LEFTNOWORDWRAP
value|(0xcL)
end_define

begin_define
define|#
directive|define
name|SS_NOPREFIX
value|(0x80L)
end_define

begin_define
define|#
directive|define
name|SS_NOTIFY
value|(0x100L)
end_define

begin_define
define|#
directive|define
name|SS_OWNERDRAW
value|(0xdL)
end_define

begin_define
define|#
directive|define
name|SS_REALSIZEIMAGE
value|(0x800L)
end_define

begin_define
define|#
directive|define
name|SS_RIGHT
value|(0x2L)
end_define

begin_define
define|#
directive|define
name|SS_RIGHTJUST
value|(0x400L)
end_define

begin_define
define|#
directive|define
name|SS_SIMPLE
value|(0xbL)
end_define

begin_define
define|#
directive|define
name|SS_SUNKEN
value|(0x1000L)
end_define

begin_define
define|#
directive|define
name|SS_USERITEM
value|(0xaL)
end_define

begin_define
define|#
directive|define
name|SS_WHITEFRAME
value|(0x9L)
end_define

begin_define
define|#
directive|define
name|SS_WHITERECT
value|(0x6L)
end_define

begin_define
define|#
directive|define
name|DS_3DLOOK
value|(0x4L)
end_define

begin_define
define|#
directive|define
name|DS_ABSALIGN
value|(0x1L)
end_define

begin_define
define|#
directive|define
name|DS_CENTER
value|(0x800L)
end_define

begin_define
define|#
directive|define
name|DS_CENTERMOUSE
value|(0x1000L)
end_define

begin_define
define|#
directive|define
name|DS_CONTEXTHELP
value|(0x2000L)
end_define

begin_define
define|#
directive|define
name|DS_CONTROL
value|(0x400L)
end_define

begin_define
define|#
directive|define
name|DS_FIXEDSYS
value|(0x8L)
end_define

begin_define
define|#
directive|define
name|DS_LOCALEDIT
value|(0x20L)
end_define

begin_define
define|#
directive|define
name|DS_MODALFRAME
value|(0x80L)
end_define

begin_define
define|#
directive|define
name|DS_NOFAILCREATE
value|(0x10L)
end_define

begin_define
define|#
directive|define
name|DS_NOIDLEMSG
value|(0x100L)
end_define

begin_define
define|#
directive|define
name|DS_SETFONT
value|(0x40L)
end_define

begin_define
define|#
directive|define
name|DS_SETFOREGROUND
value|(0x200L)
end_define

begin_define
define|#
directive|define
name|DS_SYSMODAL
value|(0x2L)
end_define

begin_comment
comment|/* A dialog control.  */
end_comment

begin_struct
struct|struct
name|dialog_control
block|{
comment|/* Next control.  */
name|struct
name|dialog_control
modifier|*
name|next
decl_stmt|;
comment|/* ID.  */
name|unsigned
name|short
name|id
decl_stmt|;
comment|/* Style.  */
name|unsigned
name|long
name|style
decl_stmt|;
comment|/* Extended style.  */
name|unsigned
name|long
name|exstyle
decl_stmt|;
comment|/* X coordinate.  */
name|unsigned
name|short
name|x
decl_stmt|;
comment|/* Y coordinate.  */
name|unsigned
name|short
name|y
decl_stmt|;
comment|/* Width.  */
name|unsigned
name|short
name|width
decl_stmt|;
comment|/* Height.  */
name|unsigned
name|short
name|height
decl_stmt|;
comment|/* Class name.  */
name|struct
name|res_id
name|class
decl_stmt|;
comment|/* Associated text.  */
name|struct
name|res_id
name|text
decl_stmt|;
comment|/* Extra data for the window procedure.  */
name|struct
name|rcdata_item
modifier|*
name|data
decl_stmt|;
comment|/* Help ID.  Only used in an extended dialog.  */
name|unsigned
name|long
name|help
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Control classes.  These can be used as the ID field in a struct    dialog_control.  */
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
comment|/* A fontdir resource is a list of fontdir structures.  */
end_comment

begin_struct
struct|struct
name|fontdir
block|{
name|struct
name|fontdir
modifier|*
name|next
decl_stmt|;
comment|/* Index of font entry.  */
name|short
name|index
decl_stmt|;
comment|/* Length of font information.  */
name|unsigned
name|long
name|length
decl_stmt|;
comment|/* Font information.  */
specifier|const
name|unsigned
name|char
modifier|*
name|data
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* A group_icon resource is a list of group_icon structures.  */
end_comment

begin_struct
struct|struct
name|group_icon
block|{
comment|/* Next icon in group.  */
name|struct
name|group_icon
modifier|*
name|next
decl_stmt|;
comment|/* Width.  */
name|unsigned
name|char
name|width
decl_stmt|;
comment|/* Height.  */
name|unsigned
name|char
name|height
decl_stmt|;
comment|/* Color count.  */
name|unsigned
name|char
name|colors
decl_stmt|;
comment|/* Planes.  */
name|unsigned
name|short
name|planes
decl_stmt|;
comment|/* Bits per pixel.  */
name|unsigned
name|short
name|bits
decl_stmt|;
comment|/* Number of bytes in cursor resource.  */
name|unsigned
name|long
name|bytes
decl_stmt|;
comment|/* Index of cursor resource.  */
name|unsigned
name|short
name|index
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* A menu resource.  */
end_comment

begin_struct
struct|struct
name|menu
block|{
comment|/* List of menuitems.  */
name|struct
name|menuitem
modifier|*
name|items
decl_stmt|;
comment|/* Help ID.  I don't think there is any way to set this in an rc      file, but it can appear in the binary format.  */
name|unsigned
name|long
name|help
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* A menu resource is a list of menuitem structures.  */
end_comment

begin_struct
struct|struct
name|menuitem
block|{
comment|/* Next menuitem.  */
name|struct
name|menuitem
modifier|*
name|next
decl_stmt|;
comment|/* Type.  In a normal menu, rather than a menuex, this is the flags      field.  */
name|unsigned
name|long
name|type
decl_stmt|;
comment|/* State.  This is only used in a menuex.  */
name|unsigned
name|long
name|state
decl_stmt|;
comment|/* Id.  */
name|unsigned
name|short
name|id
decl_stmt|;
comment|/* Unicode text.  */
name|unichar
modifier|*
name|text
decl_stmt|;
comment|/* Popup menu items for a popup.  */
name|struct
name|menuitem
modifier|*
name|popup
decl_stmt|;
comment|/* Help ID.  This is only used in a menuex.  */
name|unsigned
name|long
name|help
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Menu item flags.  These can appear in the flags field of a struct    menuitem.  */
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
comment|/* An rcdata resource is a pointer to a list of rcdata_item    structures.  */
end_comment

begin_struct
struct|struct
name|rcdata_item
block|{
comment|/* Next data item.  */
name|struct
name|rcdata_item
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
name|unsigned
name|int
name|word
decl_stmt|;
name|unsigned
name|long
name|dword
decl_stmt|;
struct|struct
block|{
name|unsigned
name|long
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
name|unsigned
name|long
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
name|unsigned
name|long
name|length
decl_stmt|;
specifier|const
name|unsigned
name|char
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
struct|;
end_struct

begin_comment
comment|/* A stringtable resource is a pointer to a stringtable structure.  */
end_comment

begin_struct
struct|struct
name|stringtable
block|{
comment|/* Each stringtable resource is a list of 16 unicode strings.  */
struct|struct
block|{
comment|/* Length of string.  */
name|int
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
struct|;
end_struct

begin_comment
comment|/* A versioninfo resource points to a versioninfo structure.  */
end_comment

begin_struct
struct|struct
name|versioninfo
block|{
comment|/* Fixed version information.  */
name|struct
name|fixed_versioninfo
modifier|*
name|fixed
decl_stmt|;
comment|/* Variable version information.  */
name|struct
name|ver_info
modifier|*
name|var
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* The fixed portion of a versioninfo resource.  */
end_comment

begin_struct
struct|struct
name|fixed_versioninfo
block|{
comment|/* The file version, which is two 32 bit integers.  */
name|unsigned
name|long
name|file_version_ms
decl_stmt|;
name|unsigned
name|long
name|file_version_ls
decl_stmt|;
comment|/* The product version, which is two 32 bit integers.  */
name|unsigned
name|long
name|product_version_ms
decl_stmt|;
name|unsigned
name|long
name|product_version_ls
decl_stmt|;
comment|/* The file flags mask.  */
name|unsigned
name|long
name|file_flags_mask
decl_stmt|;
comment|/* The file flags.  */
name|unsigned
name|long
name|file_flags
decl_stmt|;
comment|/* The OS type.  */
name|unsigned
name|long
name|file_os
decl_stmt|;
comment|/* The file type.  */
name|unsigned
name|long
name|file_type
decl_stmt|;
comment|/* The file subtype.  */
name|unsigned
name|long
name|file_subtype
decl_stmt|;
comment|/* The date, which in Windows is two 32 bit integers.  */
name|unsigned
name|long
name|file_date_ms
decl_stmt|;
name|unsigned
name|long
name|file_date_ls
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* A list of variable version information.  */
end_comment

begin_struct
struct|struct
name|ver_info
block|{
comment|/* Next item.  */
name|struct
name|ver_info
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
name|ver_stringinfo
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
name|ver_varinfo
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
struct|;
end_struct

begin_comment
comment|/* A list of string version information.  */
end_comment

begin_struct
struct|struct
name|ver_stringinfo
block|{
comment|/* Next string.  */
name|struct
name|ver_stringinfo
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
struct|;
end_struct

begin_comment
comment|/* A list of variable version information.  */
end_comment

begin_struct
struct|struct
name|ver_varinfo
block|{
comment|/* Next item.  */
name|struct
name|ver_varinfo
modifier|*
name|next
decl_stmt|;
comment|/* Language ID.  */
name|unsigned
name|short
name|language
decl_stmt|;
comment|/* Character set ID.  */
name|unsigned
name|short
name|charset
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* This structure is used when converting resource information to    binary.  */
end_comment

begin_struct
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
name|unsigned
name|long
name|length
decl_stmt|;
comment|/* Data.  */
name|unsigned
name|char
modifier|*
name|data
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|int
name|verbose
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Function declarations.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|res_directory
modifier|*
name|read_rc_file
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|res_directory
modifier|*
name|read_res_file
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|res_directory
modifier|*
name|read_coff_rsrc
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|write_rc_file
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|struct
name|res_directory
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|write_res_file
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|struct
name|res_directory
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|write_coff_file
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|struct
name|res_directory
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|res_resource
modifier|*
name|bin_to_res
parameter_list|(
name|struct
name|res_id
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|,
name|unsigned
name|long
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|bindata
modifier|*
name|res_to_bin
parameter_list|(
specifier|const
name|struct
name|res_resource
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|FILE
modifier|*
name|open_file_search
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|res_alloc
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|reswr_alloc
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Resource ID handling.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|res_id_cmp
parameter_list|(
name|struct
name|res_id
parameter_list|,
name|struct
name|res_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|res_id_print
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|struct
name|res_id
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|res_ids_print
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|struct
name|res_id
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|res_string_to_id
parameter_list|(
name|struct
name|res_id
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Manipulation of the resource tree.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|res_resource
modifier|*
name|define_resource
parameter_list|(
name|struct
name|res_directory
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|struct
name|res_id
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|res_resource
modifier|*
name|define_standard_resource
parameter_list|(
name|struct
name|res_directory
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|res_id
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|extended_dialog
parameter_list|(
specifier|const
name|struct
name|dialog
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|extended_menu
parameter_list|(
specifier|const
name|struct
name|menu
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Communication between the rc file support and the parser and lexer.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|yydebug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|yyin
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|rc_filename
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|rc_lineno
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|yyparse
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|yylex
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|yyerror
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|rcparse_warning
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|rcparse_set_language
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|rcparse_discard_strings
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|rcparse_rcdata
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|rcparse_normal
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|define_accelerator
parameter_list|(
name|struct
name|res_id
parameter_list|,
specifier|const
name|struct
name|res_res_info
modifier|*
parameter_list|,
name|struct
name|accelerator
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|define_bitmap
parameter_list|(
name|struct
name|res_id
parameter_list|,
specifier|const
name|struct
name|res_res_info
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|define_cursor
parameter_list|(
name|struct
name|res_id
parameter_list|,
specifier|const
name|struct
name|res_res_info
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|define_dialog
parameter_list|(
name|struct
name|res_id
parameter_list|,
specifier|const
name|struct
name|res_res_info
modifier|*
parameter_list|,
specifier|const
name|struct
name|dialog
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|dialog_control
modifier|*
name|define_control
parameter_list|(
specifier|const
name|struct
name|res_id
parameter_list|,
name|unsigned
name|long
parameter_list|,
name|unsigned
name|long
parameter_list|,
name|unsigned
name|long
parameter_list|,
name|unsigned
name|long
parameter_list|,
name|unsigned
name|long
parameter_list|,
name|unsigned
name|long
parameter_list|,
name|unsigned
name|long
parameter_list|,
name|unsigned
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|dialog_control
modifier|*
name|define_icon_control
parameter_list|(
name|struct
name|res_id
parameter_list|,
name|unsigned
name|long
parameter_list|,
name|unsigned
name|long
parameter_list|,
name|unsigned
name|long
parameter_list|,
name|unsigned
name|long
parameter_list|,
name|unsigned
name|long
parameter_list|,
name|unsigned
name|long
parameter_list|,
name|struct
name|rcdata_item
modifier|*
parameter_list|,
name|struct
name|dialog_ex
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|define_font
parameter_list|(
name|struct
name|res_id
parameter_list|,
specifier|const
name|struct
name|res_res_info
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|define_icon
parameter_list|(
name|struct
name|res_id
parameter_list|,
specifier|const
name|struct
name|res_res_info
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|define_menu
parameter_list|(
name|struct
name|res_id
parameter_list|,
specifier|const
name|struct
name|res_res_info
modifier|*
parameter_list|,
name|struct
name|menuitem
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|menuitem
modifier|*
name|define_menuitem
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|unsigned
name|long
parameter_list|,
name|unsigned
name|long
parameter_list|,
name|unsigned
name|long
parameter_list|,
name|struct
name|menuitem
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|define_messagetable
parameter_list|(
name|struct
name|res_id
parameter_list|,
specifier|const
name|struct
name|res_res_info
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|define_rcdata
parameter_list|(
name|struct
name|res_id
parameter_list|,
specifier|const
name|struct
name|res_res_info
modifier|*
parameter_list|,
name|struct
name|rcdata_item
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|rcdata_item
modifier|*
name|define_rcdata_string
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|unsigned
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|rcdata_item
modifier|*
name|define_rcdata_number
parameter_list|(
name|unsigned
name|long
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|define_stringtable
parameter_list|(
specifier|const
name|struct
name|res_res_info
modifier|*
parameter_list|,
name|unsigned
name|long
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|define_user_data
parameter_list|(
name|struct
name|res_id
parameter_list|,
name|struct
name|res_id
parameter_list|,
specifier|const
name|struct
name|res_res_info
modifier|*
parameter_list|,
name|struct
name|rcdata_item
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|define_user_file
parameter_list|(
name|struct
name|res_id
parameter_list|,
name|struct
name|res_id
parameter_list|,
specifier|const
name|struct
name|res_res_info
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|define_versioninfo
parameter_list|(
name|struct
name|res_id
parameter_list|,
name|int
parameter_list|,
name|struct
name|fixed_versioninfo
modifier|*
parameter_list|,
name|struct
name|ver_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|ver_info
modifier|*
name|append_ver_stringfileinfo
parameter_list|(
name|struct
name|ver_info
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|ver_stringinfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|ver_info
modifier|*
name|append_ver_varfileinfo
parameter_list|(
name|struct
name|ver_info
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|ver_varinfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|ver_stringinfo
modifier|*
name|append_verval
parameter_list|(
name|struct
name|ver_stringinfo
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|ver_varinfo
modifier|*
name|append_vertrans
parameter_list|(
name|struct
name|ver_varinfo
modifier|*
parameter_list|,
name|unsigned
name|long
parameter_list|,
name|unsigned
name|long
parameter_list|)
function_decl|;
end_function_decl

end_unit

