begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*					-[Thu Mar  3 15:57:51 1983 by jkf]-  * 	config.h			$Locker:  $  * configuration dependent info  *  * $Header: config.h,v 1.13 83/09/12 15:30:30 layer Exp $  *  * (c) copyright 1982, Regents of the University of California  */
end_comment

begin_comment
comment|/*   * this file contains parameters which each site is likely to modify  * in order to personalize the configuration of Lisp at their site.  * The typical things to modifiy are:  *    [optionally] turn on GCSTRINGS  *    [optionally] provide a value for SITE   */
end_comment

begin_comment
comment|/*  * The type of machine and os this is to run on will come from  * the file lconf.h.  The lconf.h file is created by the shell script  * 'lispconf' in the directory ../..  * lconf.h will define exactly one of these symbols:  *  vax_4_2 vax_4_1c vax_4_1a vax_4_1 vax_unix_ts vax_eunice_vms  *  sun_4_2 sun_4_1c sun_unisoft dual_unisoft  pixel_unisoft  */
end_comment

begin_include
include|#
directive|include
file|"lconf.h"
end_include

begin_comment
comment|/* GCSTRINGS - define this if you want the garbage collector to reclaim  *  strings.  It is not normally set because in typical applications the  *  expense of collecting strings is not worth the amount of space  *  retrieved  */
end_comment

begin_comment
comment|/* #define GCSTRINGS */
end_comment

begin_comment
comment|/*  * set up the global defines based on the choice above  * the global names are  * machine name:  m_vax  *		  m_68k  *			m_68k_sun, m_68k_dual m_68k_pixel  * operating system:  *		  os_unix  *		     os_4_1, os_4_1a, os_4_1c, os_4_2, os_unix_ts  *		  os_vms  */
end_comment

begin_comment
comment|/* first the machine */
end_comment

begin_if
if|#
directive|if
name|vax_4_1
operator|||
name|vax_4_1a
operator|||
name|vax_4_1c
operator|||
name|vax_4_2
operator|||
name|vax_unix_ts
operator|||
name|vax_eunice_vms
end_if

begin_define
define|#
directive|define
name|m_vax
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|sun_4_2
operator|||
name|sun_4_1c
operator|||
name|sun_unisoft
end_if

begin_define
define|#
directive|define
name|m_68k
value|1
end_define

begin_define
define|#
directive|define
name|m_68k_sun
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|dual_unisoft
end_if

begin_define
define|#
directive|define
name|m_68k
value|1
end_define

begin_define
define|#
directive|define
name|m_68k_dual
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|pixel_unisoft
end_if

begin_define
define|#
directive|define
name|m_68k
value|1
end_define

begin_define
define|#
directive|define
name|m_68k_pixel
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* next the operating system */
end_comment

begin_if
if|#
directive|if
name|vax_4_1
operator|||
name|vax_4_1a
operator|||
name|vax_4_1c
operator|||
name|vax_4_2
operator|||
name|vax_unix_ts
operator|||
name|m_68k
end_if

begin_define
define|#
directive|define
name|os_unix
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|vax_4_1
end_if

begin_define
define|#
directive|define
name|os_4_1
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|vax_4_1a
end_if

begin_define
define|#
directive|define
name|os_4_1a
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|vax_4_1c
operator|||
name|sun_4_1c
end_if

begin_define
define|#
directive|define
name|os_4_1c
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|vax_4_2
operator|||
name|sun_4_2
end_if

begin_define
define|#
directive|define
name|os_4_2
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|vax_unix_ts
end_if

begin_define
define|#
directive|define
name|os_unix_ts
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|vax_eunice_vms
end_if

begin_define
define|#
directive|define
name|os_vms
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|sun_unisoft
operator|||
name|dual_unisoft
operator|||
name|pixel_unisoft
end_if

begin_define
define|#
directive|define
name|os_unisoft
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MACHINE -  this is put on the (status features) list */
end_comment

begin_if
if|#
directive|if
name|m_68k
end_if

begin_define
define|#
directive|define
name|MACHINE
value|"68k"
end_define

begin_define
define|#
directive|define
name|PORTABLE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|m_vax
end_if

begin_define
define|#
directive|define
name|MACHINE
value|"vax"
end_define

begin_define
define|#
directive|define
name|NILIS0
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OFFSET -  this is the offset to the users address space. */
end_comment

begin_comment
comment|/* NB: this is not necessarily tied to the hardware.  Pixel    informs us that when they put up 4.1 the offsetis likely    to change */
end_comment

begin_comment
comment|/* ** NILIS0 -- for any UNIX implementation in which the users **	address space starts at 0 (like m_vax, above).  ** ** NPINREG -- for the verison if lisp that keeps np and lbot in global **	registers.  On the 68000, there is a special `hacked' version **	of the C compiler that is needed to do this. ** ** #define NILIS0		1 ** #define NPINREG		1 */
end_comment

begin_comment
comment|/*  * SPISFP -- this is to indicate that the stack and frame pointer  * are the same, or at least that you can't pull the same shenanigans  * as on the vax or sun by pushing error frames at the end of C  * frames and using alloca.  This should make life easier for  * a native VMS version or IBM or RIDGE or Bellmac-32.  * #define SPISFP 1  */
end_comment

begin_if
if|#
directive|if
name|m_vax
end_if

begin_define
define|#
directive|define
name|OFFSET
value|0x0
end_define

begin_define
define|#
directive|define
name|NPINREG
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|m_68k_sun
end_if

begin_define
define|#
directive|define
name|OFFSET
value|0x8000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|m_68k_dual
end_if

begin_define
define|#
directive|define
name|OFFSET
value|0x800000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|m_68k_pixel
end_if

begin_define
define|#
directive|define
name|OFFSET
value|0x20000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OS -  this is put on the (status features) list */
end_comment

begin_if
if|#
directive|if
name|os_unix
end_if

begin_define
define|#
directive|define
name|OS
value|"unix"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|os_vms
end_if

begin_define
define|#
directive|define
name|OS
value|"vms"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DOMAIN - this is put on the (status features) list and  * 	is the value of (status domain)  */
end_comment

begin_define
define|#
directive|define
name|DOMAIN
value|"ucb"
end_define

begin_comment
comment|/* SITE - the name of the particular machine this lisp is running on  *    this value is available via (sys:gethostname).  *    On 4.1a systems it is possible to determine this dynamically cheaply  */
end_comment

begin_if
if|#
directive|if
operator|!
operator|(
name|os_4_1a
operator|||
name|os_4_1c
operator|||
name|os_4_2
operator|)
end_if

begin_define
define|#
directive|define
name|SITE
value|"unknown-site"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  TTSIZ is the absolute limit, in pages (both text and data), of the  * size to which the lisp system may grow.  * If you change this, you must recompile alloc.c and data.c.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HOLE
end_ifdef

begin_define
define|#
directive|define
name|TTSIZE
value|10216
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TTSIZE
value|6120
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|m_vms
end_if

begin_undef
undef|#
directive|undef
name|TTSIZE
end_undef

begin_define
define|#
directive|define
name|TTSIZE
value|10216
end_define

begin_define
define|#
directive|define
name|FREESIZE
value|512 * 10000
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

