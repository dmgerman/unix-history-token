begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1989, 1992 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* gp_itbc.c */
end_comment

begin_comment
comment|/* Intel processor, Turbo/Borland C-specific routines for Ghostscript */
end_comment

begin_include
include|#
directive|include
file|"dos_.h"
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<io.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|"string_.h"
end_include

begin_include
include|#
directive|include
file|"gx.h"
end_include

begin_include
include|#
directive|include
file|"gp.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__OVERLAY__
end_ifdef

begin_include
include|#
directive|include
file|"overlay.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define the size of the C stack. */
end_comment

begin_decl_stmt
name|unsigned
name|_stklen
init|=
literal|8000
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* default is 4096, we need more */
end_comment

begin_comment
comment|/* Define the size of the overlay buffer, if relevant. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__OVERLAY__
end_ifdef

begin_decl_stmt
name|unsigned
name|_ovrbuffer
init|=
operator|(
literal|1024L
operator|*
name|OVLBUFK
operator|)
operator|/
literal|16
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Forward declarations */
end_comment

begin_decl_stmt
name|private
name|void
name|handle_FPE
argument_list|(
name|P3
argument_list|(
name|int
argument_list|,
name|int
argument_list|,
name|int
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Do platform-dependent initialization. */
end_comment

begin_if
if|#
directive|if
name|CPU_TYPE
operator|>
literal|86
end_if

begin_comment
comment|/* Internal routine to set flags and read them back. */
end_comment

begin_comment
comment|/* We use __emit__ so we don't require an assembler. */
end_comment

begin_function
name|private
name|int
name|push_pop_flags
parameter_list|(
name|unsigned
name|flags
parameter_list|)
block|{
name|__emit__
argument_list|(
literal|0x8b
argument_list|,
literal|0x46
argument_list|,
literal|6
argument_list|)
expr_stmt|;
comment|/* mov ax,flags */
name|__emit__
argument_list|(
literal|0x50
argument_list|,
literal|0x9d
argument_list|)
expr_stmt|;
comment|/* push ax; popf */
name|__emit__
argument_list|(
literal|0x9c
argument_list|,
literal|0x58
argument_list|)
expr_stmt|;
comment|/* pushf; pop ax */
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|void
name|gp_init_console
argument_list|(
name|P0
argument_list|()
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|gp_init
parameter_list|()
block|{
comment|/* 	 * Detect the processor type using the following algorithms: 	 *	The 8088/8086 truncate shift counts mod 32, 	 *	  the 80186 and up do not. 	 *	The 80186 and below fix FLAGS bits 15-12 to 1, 	 *	  the 80286 and up do not. 	 *	The 80386 allows setting FLAGS bits 14-12, 	 *	  the 80286 and below do not. 	 * We currently can't tell an 80386 from an 80486. 	 * Note that this algorithm will identify an 80386 	 *   running in Virtual 8086 mode as an 80386. 	 *   This is acceptable, because Ghostscript doesn't actually 	 *   use 80286 or 80386 addressing modes, only the additional 	 *   instructions available on these processors. 	 * (This algorithm is derived from the Intel manuals.) 	 */
if|#
directive|if
name|CPU_TYPE
operator|>
literal|86
comment|/* We have to be careful not to turn interrupts off! */
name|int
name|result
decl_stmt|,
name|type
decl_stmt|;
name|result
operator|=
name|push_pop_flags
argument_list|(
literal|0x202
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|result
operator|&
literal|0xf000
operator|)
operator|==
literal|0xf000
condition|)
block|{
comment|/* CPU is an 8088/8086/80186 */
block|{
name|int
name|shc
init|=
literal|33
decl_stmt|;
comment|/* force shift by variable */
name|result
operator|=
literal|0xffff
operator|<<
name|shc
expr_stmt|;
block|}
name|type
operator|=
operator|(
name|result
operator|==
literal|0
condition|?
literal|186
else|:
literal|86
operator|)
expr_stmt|;
block|}
else|else
block|{
comment|/* CPU is an 80286/80386/... */
name|result
operator|=
name|push_pop_flags
argument_list|(
literal|0x7202
argument_list|)
expr_stmt|;
name|type
operator|=
operator|(
operator|(
name|result
operator|&
literal|0x7000
operator|)
operator|==
literal|0
condition|?
literal|286
else|:
literal|386
operator|)
expr_stmt|;
block|}
comment|/* A 486 is the same as a 386. */
define|#
directive|define
name|CPU_EQUIV
value|(CPU_TYPE == 486 ? 386 : CPU_TYPE)
if|if
condition|(
name|type
operator|<
name|CPU_EQUIV
condition|)
block|{
name|eprintf1
argument_list|(
literal|"This executable requires an 80%d or higher.\n"
argument_list|,
name|CPU_EQUIV
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
name|_fmode
operator|=
name|O_BINARY
expr_stmt|;
comment|/* Open files in 'binary' mode */
ifdef|#
directive|ifdef
name|__OVERLAY__
comment|/* Initialize the overlay machinery. */
block|{
name|int
name|code
decl_stmt|;
ifdef|#
directive|ifdef
name|OVEMS
name|code
operator|=
name|_OvrInitEms
argument_list|(
name|OVEMS_HANDLE
argument_list|,
name|OVEMS_FIRST
argument_list|,
name|OVEMS_PAGES
argument_list|)
expr_stmt|;
if|if
condition|(
name|code
condition|)
name|eprintf
argument_list|(
literal|"Attempt to use EMS memory for overlays failed.\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|OVEXT
name|code
operator|=
name|_OvrInitExt
argument_list|(
name|OVEXT_START
argument_list|,
name|OVEXT_LENGTH
argument_list|)
expr_stmt|;
if|if
condition|(
name|code
condition|)
name|eprintf
argument_list|(
literal|"Attempt to use extended memory for overlays failed.\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
endif|#
directive|endif
comment|/* Set up the handler for numeric exceptions. */
name|signal
argument_list|(
name|SIGFPE
argument_list|,
name|handle_FPE
argument_list|)
expr_stmt|;
name|gp_init_console
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Trap numeric exceptions.  Someday we will do something */
end_comment

begin_comment
comment|/* more appropriate with these. */
end_comment

begin_function
name|private
name|void
name|handle_FPE
parameter_list|(
name|int
name|sig
parameter_list|,
name|int
name|subcode
parameter_list|,
name|int
modifier|*
name|regs
parameter_list|)
block|{
name|eprintf
argument_list|(
literal|"Numeric exception:\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|estderr
argument_list|,
literal|"AX=%04x  BX=%04x  CX=%04x  DX=%04x  SI=%04x  DI=%04x  BP=%04x\n"
argument_list|,
name|regs
index|[
literal|8
index|]
argument_list|,
name|regs
index|[
literal|7
index|]
argument_list|,
name|regs
index|[
literal|6
index|]
argument_list|,
name|regs
index|[
literal|5
index|]
argument_list|,
name|regs
index|[
literal|2
index|]
argument_list|,
name|regs
index|[
literal|1
index|]
argument_list|,
name|regs
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|estderr
argument_list|,
literal|"DS=%04x  ES=%04x  CS:IP=%04x:%04x\n"
argument_list|,
name|regs
index|[
literal|3
index|]
argument_list|,
name|regs
index|[
literal|4
index|]
argument_list|,
name|regs
index|[
literal|10
index|]
argument_list|,
name|regs
index|[
literal|9
index|]
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Do platform-dependent cleanup. */
end_comment

begin_function
name|void
name|gp_exit
parameter_list|()
block|{ }
end_function

begin_comment
comment|/* ------ Printer accessing ------ */
end_comment

begin_comment
comment|/* Open a connection to a printer.  A null file name means use the */
end_comment

begin_comment
comment|/* standard printer connected to the machine, if any. */
end_comment

begin_comment
comment|/* Return NULL if the connection could not be opened. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|gp_set_printer_binary
argument_list|(
name|P1
argument_list|(
name|int
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|FILE
modifier|*
name|gp_open_printer
parameter_list|(
name|char
modifier|*
name|fname
parameter_list|)
block|{
if|if
condition|(
name|strlen
argument_list|(
name|fname
argument_list|)
operator|==
literal|0
operator|||
operator|!
name|strcmp
argument_list|(
name|fname
argument_list|,
literal|"PRN"
argument_list|)
condition|)
block|{
name|gp_set_printer_binary
argument_list|(
name|fileno
argument_list|(
name|stdprn
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|stdprn
return|;
block|}
else|else
return|return
name|fopen
argument_list|(
name|fname
argument_list|,
literal|"wb"
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* Close the connection to the printer. */
end_comment

begin_function
name|void
name|gp_close_printer
parameter_list|(
name|FILE
modifier|*
name|pfile
parameter_list|,
specifier|const
name|char
modifier|*
name|fname
parameter_list|)
block|{
if|if
condition|(
name|pfile
operator|!=
name|stdprn
condition|)
name|fclose
argument_list|(
name|pfile
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* ------ File names ------ */
end_comment

begin_comment
comment|/* Create and open a scratch file with a given name prefix. */
end_comment

begin_comment
comment|/* Write the actual file name at fname. */
end_comment

begin_function
name|FILE
modifier|*
name|gp_open_scratch_file
parameter_list|(
specifier|const
name|char
modifier|*
name|prefix
parameter_list|,
name|char
modifier|*
name|fname
parameter_list|,
specifier|const
name|char
modifier|*
name|mode
parameter_list|)
block|{
name|strcpy
argument_list|(
name|fname
argument_list|,
name|prefix
argument_list|)
expr_stmt|;
name|strcat
argument_list|(
name|fname
argument_list|,
literal|"XXXXXX"
argument_list|)
expr_stmt|;
name|mktemp
argument_list|(
name|fname
argument_list|)
expr_stmt|;
return|return
name|fopen
argument_list|(
name|fname
argument_list|,
name|mode
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* ------ File operations ------ */
end_comment

begin_comment
comment|/* If the file given by fname exists, fill in its status and return 1; */
end_comment

begin_comment
comment|/* otherwise return 0. */
end_comment

begin_function
name|int
name|gp_file_status
parameter_list|(
specifier|const
name|char
modifier|*
name|fname
parameter_list|,
name|file_status
modifier|*
name|pstatus
parameter_list|)
block|{
name|FILE
modifier|*
name|f
init|=
name|fopen
argument_list|(
name|fname
argument_list|,
literal|"r"
argument_list|)
decl_stmt|;
name|long
name|flen
decl_stmt|;
name|struct
name|ftime
name|ft
decl_stmt|;
if|if
condition|(
name|f
operator|==
name|NULL
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|getftime
argument_list|(
name|fileno
argument_list|(
name|f
argument_list|)
argument_list|,
operator|&
name|ft
argument_list|)
operator|<
literal|0
condition|)
block|{
name|fclose
argument_list|(
name|f
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
name|fseek
argument_list|(
name|f
argument_list|,
literal|0
argument_list|,
name|SEEK_END
argument_list|)
expr_stmt|;
name|flen
operator|=
name|ftell
argument_list|(
name|f
argument_list|)
expr_stmt|;
name|pstatus
operator|->
name|size_pages
operator|=
operator|(
name|flen
operator|+
literal|1023
operator|)
operator|>>
literal|10
expr_stmt|;
name|pstatus
operator|->
name|size_bytes
operator|=
name|flen
expr_stmt|;
comment|/* Make a single long value from the ftime structure. */
name|pstatus
operator|->
name|time_referenced
operator|=
name|pstatus
operator|->
name|time_created
operator|=
operator|(
call|(
name|long
call|)
argument_list|(
operator|(
name|ft
operator|.
name|ft_year
operator|<<
literal|9
operator|)
operator|+
operator|(
name|ft
operator|.
name|ft_month
operator|<<
literal|5
operator|)
operator|+
name|ft
operator|.
name|ft_day
argument_list|)
operator|<<
literal|16
operator|)
operator|+
operator|(
operator|(
name|ft
operator|.
name|ft_hour
operator|<<
literal|11
operator|)
operator|+
operator|(
name|ft
operator|.
name|ft_min
operator|<<
literal|5
operator|)
operator|+
name|ft
operator|.
name|ft_tsec
operator|)
expr_stmt|;
name|fclose
argument_list|(
name|f
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
end_function

end_unit

