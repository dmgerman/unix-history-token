begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 Keith Muller.  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Keith Muller of the University of California, San Diego.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)extern.h	8.2 (Berkeley) 4/18/94  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * External references from each source file  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_comment
comment|/*  * ar_io.c  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|arcname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|gzip_program
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|ar_open
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ar_close
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ar_drain
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ar_set_wr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ar_app_ok
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ar_read
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ar_write
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ar_rdsync
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ar_fow
parameter_list|(
name|off_t
parameter_list|,
name|off_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ar_rev
parameter_list|(
name|off_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ar_next
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * ar_subs.c  */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|flcnt
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|list
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|extract
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|append
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|archive
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|copy
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * buf_subs.c  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|blksz
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|wrblksz
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|maxflt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|rdblksz
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|off_t
name|wrlimit
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|off_t
name|rdcnt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|off_t
name|wrcnt
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|wr_start
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rd_start
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cp_start
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|appnd_start
parameter_list|(
name|off_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rd_sync
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pback
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rd_skip
parameter_list|(
name|off_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wr_fin
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wr_rdbuf
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rd_wrbuf
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wr_skip
parameter_list|(
name|off_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wr_rdfile
parameter_list|(
name|ARCHD
modifier|*
parameter_list|,
name|int
parameter_list|,
name|off_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rd_wrfile
parameter_list|(
name|ARCHD
modifier|*
parameter_list|,
name|int
parameter_list|,
name|off_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cp_file
parameter_list|(
name|ARCHD
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|buf_fill
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|buf_flush
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * cache.c  */
end_comment

begin_function_decl
name|int
name|uidtb_start
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gidtb_start
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|usrtb_start
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|grptb_start
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|name_uid
parameter_list|(
name|uid_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|name_gid
parameter_list|(
name|gid_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|uid_name
parameter_list|(
name|char
modifier|*
parameter_list|,
name|uid_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gid_name
parameter_list|(
name|char
modifier|*
parameter_list|,
name|gid_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * cpio.c  */
end_comment

begin_function_decl
name|int
name|cpio_strd
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cpio_trail
parameter_list|(
name|ARCHD
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cpio_endwr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cpio_id
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cpio_rd
parameter_list|(
name|ARCHD
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|off_t
name|cpio_endrd
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cpio_stwr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cpio_wr
parameter_list|(
name|ARCHD
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vcpio_id
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|crc_id
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|crc_strd
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vcpio_rd
parameter_list|(
name|ARCHD
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|off_t
name|vcpio_endrd
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|crc_stwr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vcpio_wr
parameter_list|(
name|ARCHD
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bcpio_id
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bcpio_rd
parameter_list|(
name|ARCHD
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|off_t
name|bcpio_endrd
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bcpio_wr
parameter_list|(
name|ARCHD
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * file_subs.c  */
end_comment

begin_function_decl
name|int
name|file_creat
parameter_list|(
name|ARCHD
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|file_close
parameter_list|(
name|ARCHD
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lnk_creat
parameter_list|(
name|ARCHD
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cross_lnk
parameter_list|(
name|ARCHD
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chk_same
parameter_list|(
name|ARCHD
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|node_creat
parameter_list|(
name|ARCHD
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unlnk_exist
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chk_path
parameter_list|(
name|char
modifier|*
parameter_list|,
name|uid_t
parameter_list|,
name|gid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|set_ftime
parameter_list|(
name|char
modifier|*
name|fnm
parameter_list|,
name|time_t
name|mtime
parameter_list|,
name|time_t
name|atime
parameter_list|,
name|int
name|frc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|set_ids
parameter_list|(
name|char
modifier|*
parameter_list|,
name|uid_t
parameter_list|,
name|gid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|set_lids
parameter_list|(
name|char
modifier|*
parameter_list|,
name|uid_t
parameter_list|,
name|gid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|set_pmode
parameter_list|(
name|char
modifier|*
parameter_list|,
name|mode_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|file_write
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|file_flush
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rdfile_close
parameter_list|(
name|ARCHD
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|set_crc
parameter_list|(
name|ARCHD
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * ftree.c  */
end_comment

begin_function_decl
name|int
name|ftree_start
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ftree_add
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ftree_sel
parameter_list|(
name|ARCHD
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ftree_chk
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|next_file
parameter_list|(
name|ARCHD
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * gen_subs.c  */
end_comment

begin_function_decl
name|void
name|ls_list
parameter_list|(
name|ARCHD
modifier|*
parameter_list|,
name|time_t
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ls_tty
parameter_list|(
name|ARCHD
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|l_strncpy
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_long
name|asc_ul
parameter_list|(
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
name|int
name|ul_asc
parameter_list|(
name|u_long
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|NET2_STAT
end_ifndef

begin_function_decl
name|u_quad_t
name|asc_uqd
parameter_list|(
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
name|int
name|uqd_asc
parameter_list|(
name|u_quad_t
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * getoldopt.c  */
end_comment

begin_function_decl
name|int
name|getoldopt
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * options.c  */
end_comment

begin_decl_stmt
specifier|extern
name|FSUB
name|fsub
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ford
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|options
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|OPLIST
modifier|*
name|opt_next
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|opt_add
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bad_opt
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|char
modifier|*
name|chdname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * pat_rep.c  */
end_comment

begin_function_decl
name|int
name|rep_add
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pat_add
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pat_chk
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pat_sel
parameter_list|(
name|ARCHD
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pat_match
parameter_list|(
name|ARCHD
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mod_name
parameter_list|(
name|ARCHD
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|set_dest
parameter_list|(
name|ARCHD
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * pax.c  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|act
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FSUB
modifier|*
name|frmt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|cflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|cwdfd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|dflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|iflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|kflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|lflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|uflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|vflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|Dflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|Hflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|Lflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|Xflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|Yflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|Zflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|vfpart
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|patime
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pmtime
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nodirs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pmode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pids
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|rmleadslash
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|exit_val
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|docrc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|dirptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|argv0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|listf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|tempfile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|tempbase
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|sig_cleanup
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * sel_subs.c  */
end_comment

begin_function_decl
name|int
name|sel_chk
parameter_list|(
name|ARCHD
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|grp_add
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|usr_add
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|trng_add
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * tables.c  */
end_comment

begin_function_decl
name|int
name|lnk_start
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chk_lnk
parameter_list|(
name|ARCHD
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|purg_lnk
parameter_list|(
name|ARCHD
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lnk_end
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ftime_start
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chk_ftime
parameter_list|(
name|ARCHD
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|name_start
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|add_name
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sub_name
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dev_start
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|add_dev
parameter_list|(
name|ARCHD
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|map_dev
parameter_list|(
name|ARCHD
modifier|*
parameter_list|,
name|u_long
parameter_list|,
name|u_long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atdir_start
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atdir_end
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|add_atdir
parameter_list|(
name|char
modifier|*
parameter_list|,
name|dev_t
parameter_list|,
name|ino_t
parameter_list|,
name|time_t
parameter_list|,
name|time_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|get_atdir
parameter_list|(
name|dev_t
parameter_list|,
name|ino_t
parameter_list|,
name|time_t
modifier|*
parameter_list|,
name|time_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dir_start
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|add_dir
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|stat
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|proc_dir
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|st_hash
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * tar.c  */
end_comment

begin_function_decl
name|int
name|tar_endwr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|off_t
name|tar_endrd
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tar_trail
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tar_id
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tar_opt
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tar_rd
parameter_list|(
name|ARCHD
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tar_wr
parameter_list|(
name|ARCHD
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ustar_strd
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ustar_stwr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ustar_id
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ustar_rd
parameter_list|(
name|ARCHD
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ustar_wr
parameter_list|(
name|ARCHD
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * tty_subs.c  */
end_comment

begin_function_decl
name|int
name|tty_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tty_prnt
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|tty_read
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|paxwarn
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|syswarn
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

end_unit

