begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Chris Torek.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)kdbreg.h	7.2 (Berkeley) 7/9/88  */
end_comment

begin_comment
comment|/*  * The KDB50 registers are embedded inside the bi interface  * general-purpose registers.  */
end_comment

begin_struct
struct|struct
name|kdb_regs
block|{
name|struct
name|biiregs
name|kdb_bi
decl_stmt|;
name|short
name|kdb_xxx
decl_stmt|;
comment|/* first half of GPR 0 unused */
name|short
name|kdb_ip
decl_stmt|;
comment|/* initialisation and polling */
name|short
name|kdb_sa
decl_stmt|;
comment|/* status& address (r/o half) */
name|short
name|kdb_sw
decl_stmt|;
comment|/* status& address (w/o half) */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Bits in KDB status register during initialisation  */
end_comment

begin_define
define|#
directive|define
name|KDB_ERR
value|0x8000
end_define

begin_comment
comment|/* error */
end_comment

begin_define
define|#
directive|define
name|KDB_STEP4
value|0x4000
end_define

begin_comment
comment|/* step 4 has started */
end_comment

begin_define
define|#
directive|define
name|KDB_STEP3
value|0x2000
end_define

begin_comment
comment|/* step 3 has started */
end_comment

begin_define
define|#
directive|define
name|KDB_STEP2
value|0x1000
end_define

begin_comment
comment|/* step 2 has started */
end_comment

begin_define
define|#
directive|define
name|KDB_STEP1
value|0x0800
end_define

begin_comment
comment|/* step 1 has started */
end_comment

begin_define
define|#
directive|define
name|KDB_DI
value|0x0100
end_define

begin_comment
comment|/* controller implements diagnostics */
end_comment

begin_define
define|#
directive|define
name|KDB_IE
value|0x0080
end_define

begin_comment
comment|/* interrupt enable */
end_comment

begin_define
define|#
directive|define
name|KDB_NCNRMASK
value|0x003f
end_define

begin_comment
comment|/* in STEP1, bits 0-2=NCMDL2, 3-5=NRSPL2 */
end_comment

begin_define
define|#
directive|define
name|KDB_IVECMASK
value|0x007f
end_define

begin_comment
comment|/* in STEP2, bits 0-6 are interruptvec / 4 */
end_comment

begin_comment
comment|/* after initialisation: */
end_comment

begin_define
define|#
directive|define
name|KDB_GO
value|0x0001
end_define

begin_comment
comment|/* run */
end_comment

begin_define
define|#
directive|define
name|KDBSR_BITS
define|\
value|"\20\20ERR\17STEP4\16STEP3\15STEP2\14STEP1\13oldNV\12oldQB\11DI\10IE\1GO"
end_define

begin_comment
comment|/*  * KDB Communications Area.  Note that this structure definition  * requires NRSP and NCMD to be defined already.  */
end_comment

begin_struct
struct|struct
name|kdbca
block|{
name|short
name|ca_xxx1
decl_stmt|;
comment|/* unused */
name|char
name|ca_xxx2
decl_stmt|;
comment|/* unused */
name|char
name|ca_bdp
decl_stmt|;
comment|/* BDP to purge  XXX */
name|short
name|ca_cmdint
decl_stmt|;
comment|/* command ring transition flag */
name|short
name|ca_rspint
decl_stmt|;
comment|/* response ring transition flag */
name|long
name|ca_rspdsc
index|[
name|NRSP
index|]
decl_stmt|;
comment|/* response descriptors */
name|long
name|ca_cmddsc
index|[
name|NCMD
index|]
decl_stmt|;
comment|/* command descriptors */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Simplified routines (crash dump) use one command and one response.  */
end_comment

begin_struct
struct|struct
name|kdb1ca
block|{
name|long
name|ca_xxx
decl_stmt|;
name|short
name|ca_cmdint
decl_stmt|;
name|short
name|ca_rspint
decl_stmt|;
name|long
name|ca_rspdsc
decl_stmt|;
name|long
name|ca_cmddsc
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Asserting KDB_MAP in values placed in mscp_seq.seq_buffer tells  * the KDB to use mscp_seq.seq_mapbase as a set of PTEs and seq_buffer  * as an offset value.  Hence we need no mappings; the KDB50 reads  * the hardware page tables directly.  (Without KDB_MAP, seq_bufer  * represents the physical memory address instead, and seq_mapbase is  * unused.)  */
end_comment

begin_define
define|#
directive|define
name|KDB_MAP
value|0x80000000
end_define

begin_define
define|#
directive|define
name|KDB_PHYS
value|0
end_define

begin_comment
comment|/* pseudo flag */
end_comment

begin_comment
comment|/*  * KDB statistics.  */
end_comment

begin_define
define|#
directive|define
name|KS_MAXC
value|32
end_define

begin_struct
struct|struct
name|kdbstats
block|{
name|int
name|ks_sys
decl_stmt|;
comment|/* transfers done from Sysmap */
name|int
name|ks_paget
decl_stmt|;
comment|/* transfers done from Usrptmap */
name|int
name|ks_contig
decl_stmt|;
comment|/* transfers done from contiguous user map */
name|int
name|ks_copies
decl_stmt|;
comment|/* transfers done from pte copies */
name|int
name|ks_mapwait
decl_stmt|;
comment|/* number of out-of-map waits */
name|int
name|ks_cmd
index|[
name|KS_MAXC
index|]
decl_stmt|;
comment|/* commands started at once */
name|int
name|ks_inval
decl_stmt|;
comment|/* copies due to !PG_V */
block|}
struct|;
end_struct

end_unit

