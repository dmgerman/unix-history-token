begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)nlist.h	5.2 (Berkeley) 4/7/87  */
end_comment

begin_comment
comment|/*  * Format of a symbol table entry; this file is included by<a.out.h>  * and should be used if you aren't interested the a.out header  * or relocation information.  */
end_comment

begin_struct
struct|struct
name|nlist
block|{
name|char
modifier|*
name|n_name
decl_stmt|;
comment|/* for use when in-core */
name|unsigned
name|char
name|n_type
decl_stmt|;
comment|/* type flag, i.e. N_TEXT etc; see below */
name|char
name|n_other
decl_stmt|;
comment|/* unused */
name|short
name|n_desc
decl_stmt|;
comment|/* see<stab.h> */
name|unsigned
name|long
name|n_value
decl_stmt|;
comment|/* value of this symbol (or sdb offset) */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|n_hash
value|n_desc
end_define

begin_comment
comment|/* used internally by ld */
end_comment

begin_comment
comment|/*  * Simple values for n_type.  */
end_comment

begin_define
define|#
directive|define
name|N_UNDF
value|0x0
end_define

begin_comment
comment|/* undefined */
end_comment

begin_define
define|#
directive|define
name|N_ABS
value|0x2
end_define

begin_comment
comment|/* absolute */
end_comment

begin_define
define|#
directive|define
name|N_TEXT
value|0x4
end_define

begin_comment
comment|/* text */
end_comment

begin_define
define|#
directive|define
name|N_DATA
value|0x6
end_define

begin_comment
comment|/* data */
end_comment

begin_define
define|#
directive|define
name|N_BSS
value|0x8
end_define

begin_comment
comment|/* bss */
end_comment

begin_define
define|#
directive|define
name|N_COMM
value|0x12
end_define

begin_comment
comment|/* common (internal to ld) */
end_comment

begin_define
define|#
directive|define
name|N_FN
value|0x1e
end_define

begin_comment
comment|/* file name symbol */
end_comment

begin_define
define|#
directive|define
name|N_EXT
value|01
end_define

begin_comment
comment|/* external bit, or'ed in */
end_comment

begin_define
define|#
directive|define
name|N_TYPE
value|0x1e
end_define

begin_comment
comment|/* mask for all the type bits */
end_comment

begin_comment
comment|/*  * Sdb entries have some of the N_STAB bits set.  * These are given in<stab.h>  */
end_comment

begin_define
define|#
directive|define
name|N_STAB
value|0xe0
end_define

begin_comment
comment|/* if any of these bits set, a SDB entry */
end_comment

begin_comment
comment|/*  * Format for namelist values.  */
end_comment

begin_define
define|#
directive|define
name|N_FORMAT
value|"%08x"
end_define

end_unit

