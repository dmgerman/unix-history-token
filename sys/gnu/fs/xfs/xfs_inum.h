begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2003 Silicon Graphics, Inc.  All Rights Reserved.  *  * This program is free software; you can redistribute it and/or modify it  * under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  *  * Further, this software is distributed without any warranty that it is  * free of the rightful claim of any third person regarding infringement  * or the like.  Any license provided herein, whether implied or  * otherwise, applies only to this software file.  Patent licenses, if  * any, provided herein do not apply to combinations of this program with  * other software, or any other product whatsoever.  *  * You should have received a copy of the GNU General Public License along  * with this program; if not, write the Free Software Foundation, Inc., 59  * Temple Place - Suite 330, Boston MA 02111-1307, USA.  *  * Contact information: Silicon Graphics, Inc., 1600 Amphitheatre Pkwy,  * Mountain View, CA  94043, or:  *  * http://www.sgi.com  *  * For further information regarding this notice, see:  *  * http://oss.sgi.com/projects/GenInfo/SGIGPLNoticeExplan/  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_INUM_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_INUM_H__
end_define

begin_comment
comment|/*  * Inode number format:  * low inopblog bits - offset in block  * next agblklog bits - block number in ag  * next agno_log bits - ag number  * high agno_log-agblklog-inopblog bits - 0  */
end_comment

begin_typedef
typedef|typedef
name|__uint32_t
name|xfs_agino_t
typedef|;
end_typedef

begin_comment
comment|/* within allocation grp inode number */
end_comment

begin_comment
comment|/*  * Useful inode bits for this kernel.  * Used in some places where having 64-bits in the 32-bit kernels  * costs too much.  */
end_comment

begin_if
if|#
directive|if
name|XFS_BIG_INUMS
end_if

begin_typedef
typedef|typedef
name|xfs_ino_t
name|xfs_intino_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|__uint32_t
name|xfs_intino_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NULLFSINO
value|((xfs_ino_t)-1)
end_define

begin_define
define|#
directive|define
name|NULLAGINO
value|((xfs_agino_t)-1)
end_define

begin_struct_decl
struct_decl|struct
name|xfs_mount
struct_decl|;
end_struct_decl

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
name|XFS_WANT_FUNCS_C
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_INO_MASK
operator|)
end_if

begin_function_decl
name|__uint32_t
name|xfs_ino_mask
parameter_list|(
name|int
name|k
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_INO_MASK
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_INO_MASK
parameter_list|(
name|k
parameter_list|)
value|xfs_ino_mask(k)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_INO_MASK
parameter_list|(
name|k
parameter_list|)
value|((__uint32_t)((1ULL<< (k)) - 1))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
name|XFS_WANT_FUNCS_C
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_INO_OFFSET_BITS
operator|)
end_if

begin_function_decl
name|int
name|xfs_ino_offset_bits
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_INO_OFFSET_BITS
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_INO_OFFSET_BITS
parameter_list|(
name|mp
parameter_list|)
value|xfs_ino_offset_bits(mp)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_INO_OFFSET_BITS
parameter_list|(
name|mp
parameter_list|)
value|((mp)->m_sb.sb_inopblog)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
name|XFS_WANT_FUNCS_C
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_INO_AGBNO_BITS
operator|)
end_if

begin_function_decl
name|int
name|xfs_ino_agbno_bits
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_INO_AGBNO_BITS
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_INO_AGBNO_BITS
parameter_list|(
name|mp
parameter_list|)
value|xfs_ino_agbno_bits(mp)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_INO_AGBNO_BITS
parameter_list|(
name|mp
parameter_list|)
value|((mp)->m_sb.sb_agblklog)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
name|XFS_WANT_FUNCS_C
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_INO_AGINO_BITS
operator|)
end_if

begin_function_decl
name|int
name|xfs_ino_agino_bits
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_INO_AGINO_BITS
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_INO_AGINO_BITS
parameter_list|(
name|mp
parameter_list|)
value|xfs_ino_agino_bits(mp)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_INO_AGINO_BITS
parameter_list|(
name|mp
parameter_list|)
value|((mp)->m_agino_log)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
name|XFS_WANT_FUNCS_C
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_INO_AGNO_BITS
operator|)
end_if

begin_function_decl
name|int
name|xfs_ino_agno_bits
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_INO_AGNO_BITS
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_INO_AGNO_BITS
parameter_list|(
name|mp
parameter_list|)
value|xfs_ino_agno_bits(mp)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_INO_AGNO_BITS
parameter_list|(
name|mp
parameter_list|)
value|((mp)->m_agno_log)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
name|XFS_WANT_FUNCS_C
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_INO_BITS
operator|)
end_if

begin_function_decl
name|int
name|xfs_ino_bits
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_INO_BITS
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_INO_BITS
parameter_list|(
name|mp
parameter_list|)
value|xfs_ino_bits(mp)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_INO_BITS
parameter_list|(
name|mp
parameter_list|)
value|(XFS_INO_AGNO_BITS(mp) + XFS_INO_AGINO_BITS(mp))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
name|XFS_WANT_FUNCS_C
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_INO_TO_AGNO
operator|)
end_if

begin_function_decl
name|xfs_agnumber_t
name|xfs_ino_to_agno
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
name|xfs_ino_t
name|i
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_INO_TO_AGNO
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_INO_TO_AGNO
parameter_list|(
name|mp
parameter_list|,
name|i
parameter_list|)
value|xfs_ino_to_agno(mp,i)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_INO_TO_AGNO
parameter_list|(
name|mp
parameter_list|,
name|i
parameter_list|)
define|\
value|((xfs_agnumber_t)((i)>> XFS_INO_AGINO_BITS(mp)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
name|XFS_WANT_FUNCS_C
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_INO_TO_AGINO
operator|)
end_if

begin_function_decl
name|xfs_agino_t
name|xfs_ino_to_agino
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
name|xfs_ino_t
name|i
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_INO_TO_AGINO
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_INO_TO_AGINO
parameter_list|(
name|mp
parameter_list|,
name|i
parameter_list|)
value|xfs_ino_to_agino(mp,i)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_INO_TO_AGINO
parameter_list|(
name|mp
parameter_list|,
name|i
parameter_list|)
define|\
value|((xfs_agino_t)(i)& XFS_INO_MASK(XFS_INO_AGINO_BITS(mp)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
name|XFS_WANT_FUNCS_C
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_INO_TO_AGBNO
operator|)
end_if

begin_function_decl
name|xfs_agblock_t
name|xfs_ino_to_agbno
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
name|xfs_ino_t
name|i
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_INO_TO_AGBNO
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_INO_TO_AGBNO
parameter_list|(
name|mp
parameter_list|,
name|i
parameter_list|)
value|xfs_ino_to_agbno(mp,i)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_INO_TO_AGBNO
parameter_list|(
name|mp
parameter_list|,
name|i
parameter_list|)
define|\
value|(((xfs_agblock_t)(i)>> XFS_INO_OFFSET_BITS(mp))& \ 	 XFS_INO_MASK(XFS_INO_AGBNO_BITS(mp)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
name|XFS_WANT_FUNCS_C
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_INO_TO_OFFSET
operator|)
end_if

begin_function_decl
name|int
name|xfs_ino_to_offset
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
name|xfs_ino_t
name|i
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_INO_TO_OFFSET
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_INO_TO_OFFSET
parameter_list|(
name|mp
parameter_list|,
name|i
parameter_list|)
value|xfs_ino_to_offset(mp,i)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_INO_TO_OFFSET
parameter_list|(
name|mp
parameter_list|,
name|i
parameter_list|)
define|\
value|((int)(i)& XFS_INO_MASK(XFS_INO_OFFSET_BITS(mp)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
name|XFS_WANT_FUNCS_C
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_INO_TO_FSB
operator|)
end_if

begin_function_decl
name|xfs_fsblock_t
name|xfs_ino_to_fsb
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
name|xfs_ino_t
name|i
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_INO_TO_FSB
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_INO_TO_FSB
parameter_list|(
name|mp
parameter_list|,
name|i
parameter_list|)
value|xfs_ino_to_fsb(mp,i)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_INO_TO_FSB
parameter_list|(
name|mp
parameter_list|,
name|i
parameter_list|)
define|\
value|XFS_AGB_TO_FSB(mp, XFS_INO_TO_AGNO(mp,i), XFS_INO_TO_AGBNO(mp,i))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
name|XFS_WANT_FUNCS_C
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_AGINO_TO_INO
operator|)
end_if

begin_function_decl
name|xfs_ino_t
name|xfs_agino_to_ino
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
name|xfs_agnumber_t
name|a
parameter_list|,
name|xfs_agino_t
name|i
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_AGINO_TO_INO
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_AGINO_TO_INO
parameter_list|(
name|mp
parameter_list|,
name|a
parameter_list|,
name|i
parameter_list|)
value|xfs_agino_to_ino(mp,a,i)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_AGINO_TO_INO
parameter_list|(
name|mp
parameter_list|,
name|a
parameter_list|,
name|i
parameter_list|)
define|\
value|(((xfs_ino_t)(a)<< XFS_INO_AGINO_BITS(mp)) | (i))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
name|XFS_WANT_FUNCS_C
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_AGINO_TO_AGBNO
operator|)
end_if

begin_function_decl
name|xfs_agblock_t
name|xfs_agino_to_agbno
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
name|xfs_agino_t
name|i
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_AGINO_TO_AGBNO
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_AGINO_TO_AGBNO
parameter_list|(
name|mp
parameter_list|,
name|i
parameter_list|)
value|xfs_agino_to_agbno(mp,i)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_AGINO_TO_AGBNO
parameter_list|(
name|mp
parameter_list|,
name|i
parameter_list|)
value|((i)>> XFS_INO_OFFSET_BITS(mp))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
name|XFS_WANT_FUNCS_C
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_AGINO_TO_OFFSET
operator|)
end_if

begin_function_decl
name|int
name|xfs_agino_to_offset
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
name|xfs_agino_t
name|i
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_AGINO_TO_OFFSET
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_AGINO_TO_OFFSET
parameter_list|(
name|mp
parameter_list|,
name|i
parameter_list|)
value|xfs_agino_to_offset(mp,i)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_AGINO_TO_OFFSET
parameter_list|(
name|mp
parameter_list|,
name|i
parameter_list|)
define|\
value|((i)& XFS_INO_MASK(XFS_INO_OFFSET_BITS(mp)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
name|XFS_WANT_FUNCS_C
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_OFFBNO_TO_AGINO
operator|)
end_if

begin_function_decl
name|xfs_agino_t
name|xfs_offbno_to_agino
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
name|xfs_agblock_t
name|b
parameter_list|,
name|int
name|o
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_OFFBNO_TO_AGINO
operator|)
end_if

begin_define
define|#
directive|define
name|XFS_OFFBNO_TO_AGINO
parameter_list|(
name|mp
parameter_list|,
name|b
parameter_list|,
name|o
parameter_list|)
value|xfs_offbno_to_agino(mp,b,o)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_OFFBNO_TO_AGINO
parameter_list|(
name|mp
parameter_list|,
name|b
parameter_list|,
name|o
parameter_list|)
define|\
value|((xfs_agino_t)(((b)<< XFS_INO_OFFSET_BITS(mp)) | (o)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_BIG_INUMS
end_if

begin_define
define|#
directive|define
name|XFS_MAXINUMBER
value|((xfs_ino_t)((1ULL<< 56) - 1ULL))
end_define

begin_define
define|#
directive|define
name|XFS_INO64_OFFSET
value|((xfs_ino_t)(1ULL<< 32))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_MAXINUMBER
value|((xfs_ino_t)((1ULL<< 32) - 1ULL))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|XFS_MAXINUMBER_32
value|((xfs_ino_t)((1ULL<< 32) - 1ULL))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_INUM_H__ */
end_comment

end_unit

