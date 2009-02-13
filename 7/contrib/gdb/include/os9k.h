begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* os9k.h  -  OS-9000 i386 module header definitions    Copyright 2000 Free Software Foundation, Inc.  This file is part of GNU CC.     GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_escape
end_escape

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MODULE_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|_MODULE_H
end_define

begin_define
define|#
directive|define
name|_MPF386
end_define

begin_comment
comment|/* Size of common header less parity field.  */
end_comment

begin_define
define|#
directive|define
name|N_M_PARITY
value|(sizeof(mh_com)-sizeof(unisgned short))
end_define

begin_define
define|#
directive|define
name|OLD_M_PARITY
value|46
end_define

begin_define
define|#
directive|define
name|M_PARITY
value|N_M_PARITY
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_MPF68K
end_ifdef

begin_define
define|#
directive|define
name|MODSYNC
value|0x4afc
end_define

begin_comment
comment|/* Module header sync code for 680x0 processors.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_MPF386
end_ifdef

begin_define
define|#
directive|define
name|MODSYNC
value|0x4afc
end_define

begin_comment
comment|/* Module header sync code for 80386 processors.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MODREV
value|1
end_define

begin_comment
comment|/* Module format revision 1.  */
end_comment

begin_define
define|#
directive|define
name|CRCCON
value|0x800063
end_define

begin_comment
comment|/* CRC polynomial constant.  */
end_comment

begin_comment
comment|/* Module access permission values.  */
end_comment

begin_define
define|#
directive|define
name|MP_OWNER_READ
value|0x0001
end_define

begin_define
define|#
directive|define
name|MP_OWNER_WRITE
value|0x0002
end_define

begin_define
define|#
directive|define
name|MP_OWNER_EXEC
value|0x0004
end_define

begin_define
define|#
directive|define
name|MP_GROUP_READ
value|0x0010
end_define

begin_define
define|#
directive|define
name|MP_GROUP_WRITE
value|0x0020
end_define

begin_define
define|#
directive|define
name|MP_GROUP_EXEC
value|0x0040
end_define

begin_define
define|#
directive|define
name|MP_WORLD_READ
value|0x0100
end_define

begin_define
define|#
directive|define
name|MP_WORLD_WRITE
value|0x0200
end_define

begin_define
define|#
directive|define
name|MP_WORLD_EXEC
value|0x0400
end_define

begin_define
define|#
directive|define
name|MP_WORLD_ACCESS
value|0x0777
end_define

begin_define
define|#
directive|define
name|MP_OWNER_MASK
value|0x000f
end_define

begin_define
define|#
directive|define
name|MP_GROUP_MASK
value|0x00f0
end_define

begin_define
define|#
directive|define
name|MP_WORLD_MASK
value|0x0f00
end_define

begin_define
define|#
directive|define
name|MP_SYSTM_MASK
value|0xf000
end_define

begin_comment
comment|/* Module Type/Language values.  */
end_comment

begin_define
define|#
directive|define
name|MT_ANY
value|0
end_define

begin_define
define|#
directive|define
name|MT_PROGRAM
value|0x0001
end_define

begin_define
define|#
directive|define
name|MT_SUBROUT
value|0x0002
end_define

begin_define
define|#
directive|define
name|MT_MULTI
value|0x0003
end_define

begin_define
define|#
directive|define
name|MT_DATA
value|0x0004
end_define

begin_define
define|#
directive|define
name|MT_TRAPLIB
value|0x000b
end_define

begin_define
define|#
directive|define
name|MT_SYSTEM
value|0x000c
end_define

begin_define
define|#
directive|define
name|MT_FILEMAN
value|0x000d
end_define

begin_define
define|#
directive|define
name|MT_DEVDRVR
value|0x000e
end_define

begin_define
define|#
directive|define
name|MT_DEVDESC
value|0x000f
end_define

begin_define
define|#
directive|define
name|MT_MASK
value|0xff00
end_define

begin_define
define|#
directive|define
name|ML_ANY
value|0
end_define

begin_define
define|#
directive|define
name|ML_OBJECT
value|1
end_define

begin_define
define|#
directive|define
name|ML_ICODE
value|2
end_define

begin_define
define|#
directive|define
name|ML_PCODE
value|3
end_define

begin_define
define|#
directive|define
name|ML_CCODE
value|4
end_define

begin_define
define|#
directive|define
name|ML_CBLCODE
value|5
end_define

begin_define
define|#
directive|define
name|ML_FRTNCODE
value|6
end_define

begin_define
define|#
directive|define
name|ML_MASK
value|0x00ff
end_define

begin_define
define|#
directive|define
name|mktypelang
parameter_list|(
name|type
parameter_list|,
name|lang
parameter_list|)
value|(((type)<< 8) | (lang))
end_define

begin_comment
comment|/* Module Attribute values.  */
end_comment

begin_define
define|#
directive|define
name|MA_REENT
value|0x80
end_define

begin_define
define|#
directive|define
name|MA_GHOST
value|0x40
end_define

begin_define
define|#
directive|define
name|MA_SUPER
value|0x20
end_define

begin_define
define|#
directive|define
name|MA_MASK
value|0xff00
end_define

begin_define
define|#
directive|define
name|MR_MASK
value|0x00ff
end_define

begin_define
define|#
directive|define
name|mkattrevs
parameter_list|(
name|attr
parameter_list|,
name|revs
parameter_list|)
value|(((attr)<< 8) | (revs))
end_define

begin_define
define|#
directive|define
name|m_user
value|m_owner.grp_usr.usr
end_define

begin_define
define|#
directive|define
name|m_group
value|m_owner.grp_usr.grp
end_define

begin_define
define|#
directive|define
name|m_group_user
value|m_owner.group_user
end_define

begin_comment
comment|/* Macro definitions for accessing module header fields.  */
end_comment

begin_define
define|#
directive|define
name|MODNAME
parameter_list|(
name|mod
parameter_list|)
value|((u_char*)((u_char*)mod + ((Mh_com)mod)->m_name))
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* Appears not to be used, and the u_int32 typedef is gone (because it    conflicted with a Mach header.  */
end_comment

begin_define
define|#
directive|define
name|MODSIZE
parameter_list|(
name|mod
parameter_list|)
value|((u_int32)((Mh_com)mod)->m_size)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 0 */
end_comment

begin_define
define|#
directive|define
name|MHCOM_BYTES_SIZE
value|80
end_define

begin_define
define|#
directive|define
name|N_BADMAG
parameter_list|(
name|a
parameter_list|)
value|(((a).a_info) != MODSYNC)
end_define

begin_typedef
typedef|typedef
struct|struct
name|mh_com
block|{
comment|/* Sync bytes ($4afc).  */
name|unsigned
name|char
name|m_sync
index|[
literal|2
index|]
decl_stmt|;
name|unsigned
name|char
name|m_sysrev
index|[
literal|2
index|]
decl_stmt|;
comment|/* System revision check value.  */
name|unsigned
name|char
name|m_size
index|[
literal|4
index|]
decl_stmt|;
comment|/* Module size.  */
name|unsigned
name|char
name|m_owner
index|[
literal|4
index|]
decl_stmt|;
comment|/* Group/user id.  */
name|unsigned
name|char
name|m_name
index|[
literal|4
index|]
decl_stmt|;
comment|/* Offset to module name.  */
name|unsigned
name|char
name|m_access
index|[
literal|2
index|]
decl_stmt|;
comment|/* Access permissions.  */
name|unsigned
name|char
name|m_tylan
index|[
literal|2
index|]
decl_stmt|;
comment|/* Type/lang.  */
name|unsigned
name|char
name|m_attrev
index|[
literal|2
index|]
decl_stmt|;
comment|/* Rev/attr.  */
name|unsigned
name|char
name|m_edit
index|[
literal|2
index|]
decl_stmt|;
comment|/* Edition.  */
name|unsigned
name|char
name|m_needs
index|[
literal|4
index|]
decl_stmt|;
comment|/* Module hardware requirements flags. (reserved).  */
name|unsigned
name|char
name|m_usage
index|[
literal|4
index|]
decl_stmt|;
comment|/* Comment string offset.  */
name|unsigned
name|char
name|m_symbol
index|[
literal|4
index|]
decl_stmt|;
comment|/* Symbol table offset.  */
name|unsigned
name|char
name|m_exec
index|[
literal|4
index|]
decl_stmt|;
comment|/* Offset to execution entry point.  */
name|unsigned
name|char
name|m_excpt
index|[
literal|4
index|]
decl_stmt|;
comment|/* Offset to exception entry point.  */
name|unsigned
name|char
name|m_data
index|[
literal|4
index|]
decl_stmt|;
comment|/* Data storage requirement.  */
name|unsigned
name|char
name|m_stack
index|[
literal|4
index|]
decl_stmt|;
comment|/* Stack size.  */
name|unsigned
name|char
name|m_idata
index|[
literal|4
index|]
decl_stmt|;
comment|/* Offset to initialized data.  */
name|unsigned
name|char
name|m_idref
index|[
literal|4
index|]
decl_stmt|;
comment|/* Offset to data reference lists.  */
name|unsigned
name|char
name|m_init
index|[
literal|4
index|]
decl_stmt|;
comment|/* Initialization routine offset.  */
name|unsigned
name|char
name|m_term
index|[
literal|4
index|]
decl_stmt|;
comment|/* Termination routine offset.  */
name|unsigned
name|char
name|m_ident
index|[
literal|2
index|]
decl_stmt|;
comment|/* Ident code for ident program.  */
name|char
name|m_spare
index|[
literal|8
index|]
decl_stmt|;
comment|/* Reserved bytes.  */
name|unsigned
name|char
name|m_parity
index|[
literal|2
index|]
decl_stmt|;
comment|/* Header parity.  */
block|}
name|mh_com
operator|,
typedef|*
name|Mh_com
typedef|;
end_typedef

begin_comment
comment|/* Executable memory module.  */
end_comment

begin_typedef
typedef|typedef
name|mh_com
modifier|*
name|Mh_exec
typedef|,
name|mh_exec
typedef|;
end_typedef

begin_comment
comment|/* Data memory module.  */
end_comment

begin_typedef
typedef|typedef
name|mh_com
modifier|*
name|Mh_data
typedef|,
name|mh_data
typedef|;
end_typedef

begin_comment
comment|/* File manager memory module.  */
end_comment

begin_typedef
typedef|typedef
name|mh_com
modifier|*
name|Mh_fman
typedef|,
name|mh_fman
typedef|;
end_typedef

begin_comment
comment|/* Device driver module.  */
end_comment

begin_typedef
typedef|typedef
name|mh_com
modifier|*
name|Mh_drvr
typedef|,
name|mh_drvr
typedef|;
end_typedef

begin_comment
comment|/* Trap handler module.  */
end_comment

begin_typedef
typedef|typedef
name|mh_com
name|mh_trap
typedef|,
modifier|*
name|Mh_trap
typedef|;
end_typedef

begin_comment
comment|/* Device descriptor module.  */
end_comment

begin_typedef
typedef|typedef
name|mh_com
modifier|*
name|Mh_dev
typedef|,
name|mh_dev
typedef|;
end_typedef

begin_comment
comment|/* Configuration module.  */
end_comment

begin_typedef
typedef|typedef
name|mh_com
modifier|*
name|Mh_config
typedef|,
name|mh_config
typedef|;
end_typedef

begin_if
if|#
directive|if
literal|0
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MODDIR_H
argument_list|)
end_if

begin_comment
comment|/* Go get _os_fmod (and others).  */
end_comment

begin_include
include|#
directive|include
file|<moddir.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
unit|error_code _os_crc (void *, u_int32, int *); error_code _os_datmod (char *, u_int32, u_int16 *, u_int16 *, u_int32, void **, mh_data **); error_code _os_get_moddir (void *, u_int32 *); error_code _os_initdata (mh_com *, void *); error_code _os_link (char **, mh_com **, void **, u_int16 *, u_int16 *); error_code _os_linkm (mh_com *, void **, u_int16 *, u_int16 *); error_code _os_load (char *, mh_com **, void **, u_int32, u_int16 *, u_int16 *, u_int32); error_code _os_mkmodule (char *, u_int32, u_int16 *, u_int16 *, u_int32, void **, mh_com **, u_int32); error_code _os_modaddr (void *, mh_com **); error_code _os_setcrc (mh_com *); error_code _os_slink (u_int32, char *, void **, void **, mh_com **); error_code _os_slinkm (u_int32, mh_com *, void **, void **); error_code _os_unlink (mh_com *); error_code _os_unload (char *, u_int32); error_code _os_tlink (u_int32, char *, void **, mh_trap **, void *, u_int32); error_code _os_tlinkm (u_int32, mh_com *, void **, void *, u_int32); error_code _os_iodel (mh_com *); error_code _os_vmodul (mh_com *, mh_com *, u_int32);
endif|#
directive|endif
end_endif

begin_comment
comment|/* 0 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

