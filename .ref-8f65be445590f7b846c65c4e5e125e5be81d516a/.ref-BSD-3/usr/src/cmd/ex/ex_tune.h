begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1979 Regents of the University of California */
end_comment

begin_comment
comment|/*  * Definitions of editor parameters and limits  */
end_comment

begin_comment
comment|/*  * Pathnames.  *  * Only exstrings is looked at "+4", i.e. if you give  * "/usr/lib/..." here, "/lib" will be tried only for strings.  */
end_comment

begin_include
include|#
directive|include
file|"local/uparm.h"
end_include

begin_define
define|#
directive|define
name|EXRECOVER
value|libpath(ex3.2recover)
end_define

begin_define
define|#
directive|define
name|EXPRESERVE
value|libpath(ex3.2preserve)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|VMUNIX
end_ifndef

begin_define
define|#
directive|define
name|EXSTRINGS
value|libpath(ex3.2strings)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MASTERTAGS
value|libpath(tags)
end_define

begin_comment
comment|/*  * If your system believes that tabs expand to a width other than  * 8 then your makefile should cc with -DTABS=whatever, otherwise we use 8.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TABS
end_ifndef

begin_define
define|#
directive|define
name|TABS
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Maximums  *  * The definition of LBSIZE should be the same as BUFSIZ (512 usually).  * Most other definitions are quite generous.  */
end_comment

begin_comment
comment|/* FNSIZE is also defined in expreserve.c */
end_comment

begin_define
define|#
directive|define
name|FNSIZE
value|128
end_define

begin_comment
comment|/* File name size */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VMUNIX
end_ifdef

begin_define
define|#
directive|define
name|LBSIZE
value|1024
end_define

begin_define
define|#
directive|define
name|ESIZE
value|512
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LBSIZE
value|512
end_define

begin_comment
comment|/* Line length */
end_comment

begin_define
define|#
directive|define
name|ESIZE
value|128
end_define

begin_comment
comment|/* Size of compiled re */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|RHSSIZE
value|256
end_define

begin_comment
comment|/* Size of rhs of substitute */
end_comment

begin_define
define|#
directive|define
name|NBRA
value|9
end_define

begin_comment
comment|/* Number of re \( \) pairs */
end_comment

begin_define
define|#
directive|define
name|TAGSIZE
value|32
end_define

begin_comment
comment|/* Tag length */
end_comment

begin_define
define|#
directive|define
name|ONMSZ
value|32
end_define

begin_comment
comment|/* Option name size */
end_comment

begin_define
define|#
directive|define
name|GBSIZE
value|256
end_define

begin_comment
comment|/* Buffer size */
end_comment

begin_define
define|#
directive|define
name|UXBSIZE
value|128
end_define

begin_comment
comment|/* Unix command buffer size */
end_comment

begin_define
define|#
directive|define
name|VBSIZE
value|128
end_define

begin_comment
comment|/* Partial line max size in visual */
end_comment

begin_comment
comment|/* LBLKS is also defined in expreserve.c */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VMUNIX
end_ifndef

begin_define
define|#
directive|define
name|LBLKS
value|125
end_define

begin_comment
comment|/* Line pointer blocks in temp file */
end_comment

begin_define
define|#
directive|define
name|HBLKS
value|1
end_define

begin_comment
comment|/* struct header fits in BUFSIZ*HBLKS */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LBLKS
value|900
end_define

begin_define
define|#
directive|define
name|HBLKS
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MAXDIRT
value|12
end_define

begin_comment
comment|/* Max dirtcnt before sync tfile */
end_comment

begin_define
define|#
directive|define
name|TCBUFSIZE
value|1024
end_define

begin_comment
comment|/* Max entry size in termcap, see 					   also termlib and termcap */
end_comment

begin_comment
comment|/*  * Except on VMUNIX, these are a ridiculously small due to the  * lousy arglist processing implementation which fixes core  * proportional to them.  Argv (and hence NARGS) is really unnecessary,  * and argument character space not needed except when  * arguments exist.  Argument lists should be saved before the "zero"  * of the incore line information and could then  * be reasonably large.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VMUNIX
end_ifndef

begin_define
define|#
directive|define
name|NARGS
value|100
end_define

begin_comment
comment|/* Maximum number of names in "next" */
end_comment

begin_define
define|#
directive|define
name|NCARGS
value|LBSIZE
end_define

begin_comment
comment|/* Maximum arglist chars in "next" */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NCARGS
value|5120
end_define

begin_define
define|#
directive|define
name|NARGS
value|(NCARGS/6)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Note: because the routine "alloca" is not portable, TUBESIZE  * bytes are allocated on the stack each time you go into visual  * and then never freed by the system.  Thus if you have no terminals  * which are larger than 24 * 80 you may well want to make TUBESIZE  * smaller.  TUBECOLS should stay at 160 since this defines the maximum  * length of opening on hardcopies and allows two lines of open on  * terminals like adm3's (glass tty's) where it switches to pseudo  * hardcopy mode when a line gets longer than 80 characters.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VMUNIX
end_ifndef

begin_define
define|#
directive|define
name|TUBELINES
value|40
end_define

begin_comment
comment|/* Number of screen lines for visual */
end_comment

begin_define
define|#
directive|define
name|TUBECOLS
value|160
end_define

begin_comment
comment|/* Number of screen columns for visual */
end_comment

begin_define
define|#
directive|define
name|TUBESIZE
value|3400
end_define

begin_comment
comment|/* Maximum screen size for visual */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TUBELINES
value|66
end_define

begin_define
define|#
directive|define
name|TUBECOLS
value|160
end_define

begin_define
define|#
directive|define
name|TUBESIZE
value|6600
end_define

begin_comment
comment|/* 66 * 100 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Output column (and line) are set to this value on cursor addressible  * terminals when we lose track of the cursor to force cursor  * addressing to occur.  */
end_comment

begin_define
define|#
directive|define
name|UKCOL
value|-20
end_define

begin_comment
comment|/* Prototype unknown column */
end_comment

begin_comment
comment|/*  * Attention is the interrupt character (normally 0177 -- delete).  * Quit is the quit signal (normally FS -- control-\) and quits open/visual.  */
end_comment

begin_define
define|#
directive|define
name|ATTN
value|0177
end_define

begin_define
define|#
directive|define
name|QUIT
value|('\\'& 037)
end_define

end_unit

