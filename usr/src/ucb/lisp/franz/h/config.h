begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*					-[Thu Mar  3 15:57:51 1983 by jkf]-  * 	config.h			$Locker:  $  * configuration dependent info  *  * $Header: /na/franz/franz/h/RCS/config.h,v 1.7 83/03/04 12:29:58 jkf Exp $  *  * (c) copyright 1982, Regents of the University of California  */
end_comment

begin_comment
comment|/*   * this file contains parameters which each site is likely to modify  * in order to personalize the configuration of Lisp at their site.  * The typical things to modifiy are:  *    [optionally] turn on GCSTRINGS  *    [optionally] provide a value for SITE   */
end_comment

begin_comment
comment|/*  * The type of machine and os this is to run on will come from  * the file lconf.h.  The lconf.h file is created by the shell script  * 'lispconf' in the directory ../..  * lconf.h will define exactly one of these symbols:  *  vax_4_1c vax_4_1a vax_4_1 vax_unix_ts vax_eunice_vms  *  sun_4_1c sun_unisoft dual_unisoft   */
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
comment|/*  * set up the global defines based on the choice above  * the global names are  * machine name:  m_vax  *		  m_68k  *			m_68k_sun, m_68k_dual  * operating system:  *		  os_unix  *		     os_4_1, os_4_1a, os_4_1c, os_unix_ts  *		  os_vms  */
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
end_if

begin_define
define|#
directive|define
name|os_unisoft
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OFFSET -  this is the offset to the users address space. */
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
name|m_68k_unisoft
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
name|m_68k
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
value|2500
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

