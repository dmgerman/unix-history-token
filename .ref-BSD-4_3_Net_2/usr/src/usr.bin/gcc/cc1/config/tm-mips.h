begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.  MIPS version.    Contributed by   A. Lichnewsky, lich@inria.inria.fr    Changes by	    Michael Meissner, meissner@osf.org    Copyright (C) 1989, 1990 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* ??? This file needs to be reformatted so that it looks like the    rest of GCC. ???  */
end_comment

begin_comment
comment|/*----------------------------------------------------------------------  SWITCHES:      -O    optimization. Implies -mgpOPT     -O1	  Same as -O, mips compatibility     -O2   Implies -O -fomit-frame-pointer -fstrength-reduce     -O3   Implies -O2 + -finline-functions      -mG0 -mG1 -mG2           Construct a size to be passed to GCC for Data / Sdata selection.            Value is ( (i=G0 + 2 G1 + 4 G2) , (i< 6) ? ( 1<<i) :(1<<(i+3)))           Same value should be passed to as + ld using -G.  Use -G instead 	  since it is now supported.  	  Default = -mG1 -mG0 (Value = 8).      -G32  Implies -G 32 -mG2 -mnG1 -mG0.       -bestGnum           Pass -bestGnum flag to ld. This helps setting best value for           the -G parameter.      -SSYSV  for RISC-OS: use the System V environment     -SBSD43 for RISC-OS: use the BSD 4.3  environment ----------------------------------------------------------------------*/
end_comment

begin_escape
end_escape

begin_comment
comment|/* Suppression of libg.a when debugging */
end_comment

begin_define
define|#
directive|define
name|NO_LIBG
end_define

begin_comment
comment|/* Switch  Recognition by gcc.c   */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SWITCH_TAKES_ARG
end_ifdef

begin_undef
undef|#
directive|undef
name|SWITCH_TAKES_ARG
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SWITCH_TAKES_ARG
parameter_list|(
name|CHAR
parameter_list|)
define|\
value|((CHAR) == 'D' || (CHAR) == 'U' || (CHAR) == 'o' \    || (CHAR) == 'e' || (CHAR) == 'T' || (CHAR) == 'u' \    || (CHAR) == 'I' || (CHAR) == 'Y' || (CHAR) == 'm' \    || (CHAR) == 'L' || (CHAR) == 'i' || (CHAR) == 'A' \    || (CHAR) == 'G')
end_define

begin_comment
comment|/* Process -mGxx switches  */
end_comment

begin_function_decl
specifier|extern
name|void
name|overide_options
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|OVERRIDE_OPTIONS
value|overide_options ()
end_define

begin_comment
comment|/* Names to predefine in the preprocessor for this target machine.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CPP_PREDEFINES
end_ifndef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dmips -Dunix -Dhost_mips -DMIPSEB -DR3000 -DLANGUAGE_C"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Extra switches sometimes passed to the assembler.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASM_SPEC
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|OSF_OS
end_ifndef

begin_comment
comment|/* normal MIPS system */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DECSTATION
end_ifndef

begin_comment
comment|/* big endian MIPS (MIPS, SGI) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SGI_TARGET
end_ifndef

begin_comment
comment|/* not Silicon Graphics (ie, MIPSco) */
end_comment

begin_define
define|#
directive|define
name|ASM_SPEC
value|"%{!mrnames:-nocpp}				\ 			 %{!mgas:					\ 				%{pipe: %e-pipe is not supported.}	\ 				%{EB} %{!EB:-EB}			\ 				%{EL: %e-EL not supported}		\ 				%{O:-O2} %{O1:-O2} %{O2:-O2} %{O3:-O3}	\ 				%{g} %{g1} %{g2} %{g3} %{g0}}		\ 			 %{G*}						\ 			 %{!G:%{!G32:	%{mpic:-G 0} %{pic:-G 0}	\ 					%{mgas:-G 0}			\ 					%{!pic:%{!mpic:%{!mgas:-G 8}}}}	\ 				%{G32: -G 32}}				\ 			 %{v} %{K}"
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Silicon Graphics */
end_comment

begin_define
define|#
directive|define
name|ASM_SPEC
value|"%{!mrnames:-nocpp}				\ 			 %{!mgas:					\ 				%{pipe: %e-pipe is not supported.}	\ 				%{O:-O2} %{O1:-O2} %{O2:-O2} %{O3:-O3}	\ 				%{g} %{g1} %{g2} %{g3} %{g0}}		\ 			 %{G*}						\ 			 %{!G:%{!G32:	%{mpic:-G 0} %{pic:-G 0}	\ 					%{mgas:-G 0}			\ 					%{!pic:%{!mpic:%{!mgas:-G 8}}}}	\ 				%{G32: -G 32}}				\ 			 %{v} %{K}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Silicon Graphics */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Ultrix Decstation (little endian) */
end_comment

begin_define
define|#
directive|define
name|ASM_SPEC
value|"%{!mrnames:-nocpp}				\ 			 %{!mgas:					\ 				%{pipe:%e:-pipe not supported}		\ 				%{EL} %{!EL:-EL}			\ 				%{EB: %e-EB not supported}		\ 				%{O:-O2} %{O1:-O2} %{O2:-O2} %{O3:-O3}	\ 				%{g} %{g1} %{g2} %{g3} %{g0}}		\ 			 %{G*}						\ 			 %{!G:%{!G32:	%{mpic:-G 0} %{pic:-G 0}	\ 					%{mgas:-G 0}			\ 					%{!pic:%{!mpic:%{!mgas:-G 8}}}}	\ 				%{G32: -G 32}}				\ 			 %{v} %{K}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DECstation running Ultrix */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* OSF/1 of some sort */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DECSTATION
end_ifndef

begin_comment
comment|/* Big endian MIPS running OSF/1 */
end_comment

begin_define
define|#
directive|define
name|ASM_SPEC
value|"%{mmips-as:					\ 				%{pipe:%e:-pipe not supported}		\ 				%{EB} %{!EB:-EB}			\ 				%{EL: %e-EL not supported}		\ 				%{!mrnames:-nocpp}			\ 				%{O:-O2} %{O1:-O2} %{O2:-O2} %{O3:-O3}	\ 				%{g} %{g1} %{g2} %{g3} %{g0}		\ 				%{v} %{K}}				\ 			 %{G*}						\ 			 %{!G:%{!G32:	%{mpic:-G 0} %{pic:-G 0}	\ 					%{!mmips-as:-G 0}		\ 					%{!pic:%{!mpic:%{mmips-as:-G 8}}}} \ 				%{G32: -G 32}}"
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Little endian OSF/1 Decstation */
end_comment

begin_define
define|#
directive|define
name|ASM_SPEC
value|"%{mmips-as:					\ 				%{pipe:%e:-pipe not supported}		\ 				%{EL} %{!EL:-EL}			\ 				%{EB: %e-EB not supported}		\ 				%{!mrnames:-nocpp}			\ 				%{O:-O2} %{O1:-O2} %{O2:-O2} %{O3:-O3}	\ 				%{g} %{g1} %{g2} %{g3} %{g0}		\ 				%{v} %{K}}				\ 			 %{G*}						\ 			 %{!G:%{!G32:	%{mpic:-G 0} %{pic:-G 0}	\ 					%{!mmips-as:-G 0}		\ 					%{!pic:%{!mpic:%{mmips-as:-G 8}}}} \ 				%{G32: -G 32}}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* little endian OSF/1 DECstation */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OSF/1 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ASM_SPEC */
end_comment

begin_comment
comment|/* Redefinition of libraries used.  Mips doesn't support normal    UNIX style profiling via calling _mcount.  It does offer    profiling that samples the PC, so do what we can... */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LIB_SPEC
end_ifndef

begin_define
define|#
directive|define
name|LIB_SPEC
value|"%{pg:%e-pg is not supported on the MIPS}%{p:-lprof1} -lc"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Extra switches sometimes passed to the loader.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LINK_SPEC
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|MIPS_SYSV
end_ifdef

begin_comment
comment|/* RISC-OS SYSTEM V */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|STARTFILE_SPEC
end_ifndef

begin_define
define|#
directive|define
name|STARTFILE_SPEC
define|\
value|"%{pg:gcrt0.o%s}%{!pg:%{p:mcrt0.o%s}%{!p:crt1.o%s crtn.o%s}}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LINK_SPEC
value|"%{G*}						\ 		    %{!G:%{!G32:	%{mpic:-G 0} %{pic:-G 0}	\ 					%{mgas:-G 0}			\ 					%{!pic:%{!mpic:%{!mgas:-G 8}}}}	\ 			%{G32:-G 32}}					\ 		    %{!G:%{!G32:					\ 			%{mG0:%eYou should include ld/as option -G}	\ 			%{mG1:%eYou should include ld/as option -G}	\ 			%{mG2:%eYou should include ld/as option -G}}}	\ 		    %{bestGnum}						\ 		    %{!ZBSD43:-systype /sysv/}%{ZBSD43:-systype /bsd43/} \ 		    %{EB} %{!EB:-EB} %{EL:%e-EL not supported}"
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* RISC-OS SYSTEM V */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MIPS_BSD43
end_ifdef

begin_comment
comment|/* RISC-OS BSD */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|STARTFILE_SPEC
end_ifndef

begin_define
define|#
directive|define
name|STARTFILE_SPEC
define|\
value|"%{pg:gcrt0.o%s}%{!pg:%{p:mcrt0.o%s}%{!p:crt1.o%s crtn.o%s}}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LINK_SPEC
value|"%{G*}						\ 		    %{!G:%{!G32:	%{mpic:-G 0} %{pic:-G 0}	\ 					%{mgas:-G 0}			\ 					%{!pic:%{!mpic:%{!mgas:-G 8}}}}	\ 			%{G32:-G 32}}					\ 		    %{!G:%{!G32:					\ 			%{mG0:%eYou should include ld/as option -G}	\ 			%{mG1:%eYou should include ld/as option -G}	\ 			%{mG2:%eYou should include ld/as option -G}}}	\ 		    %{bestGnum}						\ 		    %{!ZSYSV:-systype /bsd43/}%{ZSYSV:-systype /sysv/}	\ 		    %{EB} %{!EB:-EB} %{EL:%e-EL not supported}"
end_define

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|DECSTATION
end_ifndef

begin_comment
comment|/* Big endian BSD or OSF/1 system */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|OSF_OS
end_ifndef

begin_comment
comment|/* Big endian BSD system */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SGI_TARGET
end_ifndef

begin_comment
comment|/* Big endian non Silicon Graphics system */
end_comment

begin_define
define|#
directive|define
name|LINK_SPEC
value|"%{G*}						\ 		    %{!G:%{!G32:	%{mpic:-G 0} %{pic:-G 0}	\ 					%{mgas:-G 0}			\ 					%{!pic:%{!mpic:%{!mgas:-G 8}}}}	\ 			%{G32:-G 32}}					\ 		    %{!G:%{!G32:					\ 			%{mG0:%eYou should include ld/as option -G}	\ 			%{mG1:%eYou should include ld/as option -G}	\ 			%{mG2:%eYou should include ld/as option -G}}}	\ 		    %{!mgas: %{EB} %{!EB:-EB} %{EL:%e-EL not supported}	\ 			     %{bestGnum}}"
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Silicon graphics system */
end_comment

begin_define
define|#
directive|define
name|LINK_SPEC
value|"%{G*}						\ 		    %{!G:%{!G32:	%{mpic:-G 0} %{pic:-G 0}	\ 					%{mgas:-G 0}			\ 					%{!pic:%{!mpic:%{!mgas:-G 8}}}}	\ 			%{G32:-G 32}}					\ 		    %{!G:%{!G32:					\ 			%{mG0:%eYou should include ld/as option -G}	\ 			%{mG1:%eYou should include ld/as option -G}	\ 			%{mG2:%eYou should include ld/as option -G}}}	\ 		    %{!mgas: %{bestGnum}}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Silicon Graphics system */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Big endian OSF/1 system */
end_comment

begin_define
define|#
directive|define
name|LINK_SPEC
value|"%{G*}						\ 		    %{!G:%{!G32:	%{mpic:-G 0} %{pic:-G 0}	\ 					%{!mmips-as:-G 0}		\ 					%{!pic:%{!mpic:%{mmips-as:-G 8}}}} \ 			%{G32:-G 32}}					\ 		    %{!G:%{!G32:					\ 			%{mG0:%eYou should include ld/as option -G}	\ 			%{mG1:%eYou should include ld/as option -G}	\ 			%{mG2:%eYou should include ld/as option -G}}}	\ 		    %{mmips-as: %{EB} %{!EB:-EB} %{EL:%e-EL not supported} \ 			%{bestGnum}}					\ 		    %{nostdlib}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Big endian BSD or OSF/1 system */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Little endian Ultrix or OSF/1 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|OSF_OS
end_ifndef

begin_comment
comment|/* Little endian Ultrix system */
end_comment

begin_define
define|#
directive|define
name|LINK_SPEC
value|"%{G*}						\ 		    %{!G:%{!G32:	%{mpic:-G 0} %{pic:-G 0}	\ 					%{mgas:-G 0}			\ 					%{!pic:%{!mpic:%{!mgas:-G 8}}}}	\ 			%{G32:-G 32}}					\ 		    %{!G:%{!G32:					\ 			%{mG0:%eYou should include ld/as option -G}	\ 			%{mG1:%eYou should include ld/as option -G}	\ 			%{mG2:%eYou should include ld/as option -G}}}	\ 		    %{!mgas: %{EL} %{!EL:-EL} %{EB:%e-EB not supported}	\ 			     %{bestGnum}}"
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Little endian OSF/1 system */
end_comment

begin_define
define|#
directive|define
name|LINK_SPEC
value|"%{G*}						\ 		    %{!G:%{!G32:	%{mpic:-G 0} %{pic:-G 0}	\ 					%{!mmips-as:-G 0}		\ 					%{!pic:%{!mpic:%{mmips-as:-G 8}}}} \ 			%{G32:-G 32}}					\ 		    %{!G:%{!G32:					\ 			%{mG0:%eYou should include ld/as option -G}	\ 			%{mG1:%eYou should include ld/as option -G}	\ 			%{mG2:%eYou should include ld/as option -G}}}	\ 		    %{mmips-as: %{EL} %{!EL:-EL} %{EB:%e-EB not supported} \ 			%{bestGnum}}					\ 		    %{nostdlib}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Little endian OSF/1 system */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Little endian BSD or OSF/1 system */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RISC-OS BSD */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RISC-OS SYSTEM V */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LINK_SPEC defined */
end_comment

begin_comment
comment|/* CC1 SPECS */
end_comment

begin_define
define|#
directive|define
name|CC1_SPEC
value|"%{O: %{!mngpOPT:-mgpOPT}}				\                     %{O1:-O %{!mngpOPT:-mgpOPT}}			\ 		    %{O2:-O %{!fnostrength-reduce:-fstrength-reduce}	\ 			    %{!fnoomit-frame-pointer:-fomit-frame-pointer} \ 			    %{!mngpOPT:-mgpOPT}}			\ 		    %{O3:-O %{!fnostrength-reduce:-fstrength-reduce}	\ 			    %{!fnoomit-frame-pointer:-fomit-frame-pointer} \ 			    %{!fnoinline-functions:-finline-functions}	\ 			    %{!mngpOPT:-mgpOPT}}			\                     %{O4:%eGCC does not support -O4}			\ 		    %{!g: %{g1:-g} %{g2:-g} %{g3:-g}}			\ 		    %{G32: -mG2 -mnG1 }"
end_define

begin_comment
comment|/* CPP SPECS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DECSTATION
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|SGI_TARGET
end_ifdef

begin_comment
comment|/* Silicon Graphics */
end_comment

begin_define
define|#
directive|define
name|CPP_SPEC
value|" %{!ansi:-D__EXTENSIONS__}				\ 		   -D_MIPSEB -D_SYSTYPE_SYSV -D_LANGUAGE_C		\ 		   %{O1:-D__OPTIMIZE__}					\ 		   %{O2:-D__OPTIMIZE__}					\ 		   %{O3:-D__OPTIMIZE__}"
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MIPS_SYSV
argument_list|)
operator|||
name|defined
argument_list|(
name|MIPS_BSD43
argument_list|)
end_if

begin_comment
comment|/* MIPS RISC-OS environments */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MIPS_SYSV
end_ifdef

begin_define
define|#
directive|define
name|CPP_SPEC
value|" %{!ansi:%{!ZBSD43:-DSYSTYPE_SYSV}%{ZBSD43:-DSYSTYPE_BSD43}}\ 		   %{!ZBSD43:-D__SYSTYPE_SYSV__}%{ZBSD43:-D__SYSTYPE_BSD43__} \ 		   %{!nostdinc:%{!ZBSD43:-I/sysv/usr/include}		\ 			       %{ZBSD43:-I/bsd43/usr/include}}		\ 		   %{O1:-D__OPTIMIZE__}					\ 		   %{O2:-D__OPTIMIZE__}					\ 		   %{O3:-D__OPTIMIZE__}"
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not MIPS_SYSV */
end_comment

begin_define
define|#
directive|define
name|CPP_SPEC
value|" %{!ansi:%{!ZSYSV:-DSYSTYPE_BSD43}%{ZSYSV:-DSYSTYPE_SYSV}}\ 		   %{!ZSYSV:-D__SYSTYPE_BSD43__}%{ZSYSV:-D__SYSTYPE_SYSV__}\ 		   %{!nostdinc:%{!ZSYSV:-I/bsd43/usr/include}		\ 			       %{ZSYSV:-I/sysv/usr/include}}		\ 		   %{O1:-D__OPTIMIZE__}					\ 		   %{O2:-D__OPTIMIZE__}					\ 		   %{O3:-D__OPTIMIZE__}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not MIPS_SYSV */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not MIPS_SYSV and not MIPS_BSD43 */
end_comment

begin_comment
comment|/* default MIPS Bsd environment */
end_comment

begin_define
define|#
directive|define
name|CPP_SPEC
value|"%{!ansi:-DSYSTYPE_BSD} -D__SYSTYPE_BSD__		\ 		   %{O1:-D__OPTIMIZE__}					\ 		   %{O2:-D__OPTIMIZE__}					\ 		   %{O3:-D__OPTIMIZE__}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not MIPS_SYSV and not MIPS_BSD43 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not Silicon Graphics */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* DECSTATION */
end_comment

begin_define
define|#
directive|define
name|CPP_SPEC
value|"%{O1:-D__OPTIMIZE__}					\ 		   %{O2:-D__OPTIMIZE__}					\ 		   %{O3:-D__OPTIMIZE__}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not DECSTATION */
end_comment

begin_escape
end_escape

begin_comment
comment|/* Print subsidiary information on the compiler version in use.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DATE__
end_ifndef

begin_define
define|#
directive|define
name|__DATE__
value|"[unknown date]"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MIPS_VERSION
value|"AL-MIPS 1.1"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DECSTATION
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|OSF_OS
end_ifdef

begin_define
define|#
directive|define
name|MACHINE_TYPE
value|"OSF/1 Dec Mips"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MACHINE_TYPE
value|"Ultrix Dec Mips"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|SGI_TARGET
end_ifdef

begin_define
define|#
directive|define
name|MACHINE_TYPE
value|"Sgi Mips"
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MIPS_SYSV
argument_list|)
operator|||
name|defined
argument_list|(
name|MIPS_BSD43
argument_list|)
end_if

begin_comment
comment|/* MIPS RISC-OS environments */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MIPS_SYSV
end_ifdef

begin_define
define|#
directive|define
name|MACHINE_TYPE
value|"RISC-OS System V Mips"
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not MIPS_SYSV */
end_comment

begin_define
define|#
directive|define
name|MACHINE_TYPE
value|"RISC-OS BSD Mips"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not MIPS_SYSV */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not MIPS_SYSV and not MIPS_BSD43 */
end_comment

begin_comment
comment|/* default MIPS Bsd environment */
end_comment

begin_define
define|#
directive|define
name|MACHINE_TYPE
value|"BSD Mips"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not SGI iris */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not MIPS_SYSV and not MIPS_BSD43 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not DECSTATION */
end_comment

begin_define
define|#
directive|define
name|TARGET_VERSION
define|\
value|{									\   fprintf (stderr, " %s %s %s", MIPS_VERSION, MACHINE_TYPE, __DATE__);	\ }
end_define

begin_escape
end_escape

begin_define
define|#
directive|define
name|SDB_DEBUGGING_INFO
end_define

begin_comment
comment|/* generate debug info inside of comments */
end_comment

begin_define
define|#
directive|define
name|MIPS_DEBUGGING_INFO
end_define

begin_comment
comment|/* MIPS specific debugging info */
end_comment

begin_comment
comment|/* On Sun 4, this limit is 2048.  We use 1500 to be safe,    since the length can run past this up to a continuation point.  */
end_comment

begin_define
define|#
directive|define
name|DBX_CONTIN_LENGTH
value|1500
end_define

begin_comment
comment|/* How to renumber registers for dbx and gdb.    MIPS needs no change in the numeration.  */
end_comment

begin_define
define|#
directive|define
name|DBX_REGISTER_NUMBER
parameter_list|(
name|REGNO
parameter_list|)
value|(REGNO)
end_define

begin_comment
comment|/* Overides for the COFF debug format.  */
end_comment

begin_define
define|#
directive|define
name|PUT_SDB_SCL
parameter_list|(
name|a
parameter_list|)
define|\
value|do {							\   extern FILE *asm_out_text_file;			\   fprintf (asm_out_text_file, "\t.scl\t%d;", (a));	\ } while (0)
end_define

begin_define
define|#
directive|define
name|PUT_SDB_INT_VAL
parameter_list|(
name|a
parameter_list|)
define|\
value|do {							\   extern FILE *asm_out_text_file;			\   fprintf (asm_out_text_file, "\t.val\t%d;", (a));	\ } while (0)
end_define

begin_define
define|#
directive|define
name|PUT_SDB_VAL
parameter_list|(
name|a
parameter_list|)
define|\
value|do {							\   extern FILE *asm_out_text_file;			\   fputs ("\t.val\t", asm_out_text_file);		\   output_addr_const (asm_out_text_file, (a));		\   fputc (';', asm_out_text_file);			\ } while (0)
end_define

begin_define
define|#
directive|define
name|PUT_SDB_DEF
parameter_list|(
name|a
parameter_list|)
define|\
value|do {							\   extern FILE *asm_out_text_file;			\   fprintf (asm_out_text_file, "\t#.def\t");		\   ASM_OUTPUT_LABELREF (asm_out_text_file, a); 		\   fputc (';', asm_out_text_file);			\ } while (0)
end_define

begin_define
define|#
directive|define
name|PUT_SDB_PLAIN_DEF
parameter_list|(
name|a
parameter_list|)
define|\
value|do {							\   extern FILE *asm_out_text_file;			\   fprintf (asm_out_text_file, "\t#.def\t.%s;", (a));	\ } while (0)
end_define

begin_define
define|#
directive|define
name|PUT_SDB_ENDEF
define|\
value|do {							\   extern FILE *asm_out_text_file;			\   fprintf (asm_out_text_file, "\t.endef\n");		\ } while (0)
end_define

begin_define
define|#
directive|define
name|PUT_SDB_TYPE
parameter_list|(
name|a
parameter_list|)
define|\
value|do {							\   extern FILE *asm_out_text_file;			\   fprintf (asm_out_text_file, "\t.type\t0x%x;", (a));	\ } while (0)
end_define

begin_define
define|#
directive|define
name|PUT_SDB_SIZE
parameter_list|(
name|a
parameter_list|)
define|\
value|do {							\   extern FILE *asm_out_text_file;			\   fprintf (asm_out_text_file, "\t.size\t%d;", (a));	\ } while (0)
end_define

begin_define
define|#
directive|define
name|PUT_SDB_DIM
parameter_list|(
name|a
parameter_list|)
define|\
value|do {							\   extern FILE *asm_out_text_file;			\   fprintf (asm_out_text_file, "\t.dim\t%d;", (a));	\ } while (0)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|PUT_SDB_START_DIM
end_ifndef

begin_define
define|#
directive|define
name|PUT_SDB_START_DIM
define|\
value|do {							\   extern FILE *asm_out_text_file;			\   fprintf (asm_out_text_file, "\t.dim\t");		\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PUT_SDB_NEXT_DIM
end_ifndef

begin_define
define|#
directive|define
name|PUT_SDB_NEXT_DIM
parameter_list|(
name|a
parameter_list|)
define|\
value|do {							\   extern FILE *asm_out_text_file;			\   fprintf (asm_out_text_file, "%d,", a);		\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PUT_SDB_LAST_DIM
end_ifndef

begin_define
define|#
directive|define
name|PUT_SDB_LAST_DIM
parameter_list|(
name|a
parameter_list|)
define|\
value|do {							\   extern FILE *asm_out_text_file;			\   fprintf (asm_out_text_file, "%d;", a);		\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PUT_SDB_TAG
parameter_list|(
name|a
parameter_list|)
define|\
value|do {							\   extern FILE *asm_out_text_file;			\   fprintf (asm_out_text_file, "\t.tag\t");		\   ASM_OUTPUT_LABELREF (asm_out_text_file, a); 		\   fputc (';', asm_out_text_file);			\ } while (0)
end_define

begin_comment
comment|/* For block start and end, we create labels, so that    later we can figure out where the correct offset is.    The normal .ent/.end serve well enough for functions,    so those are just commented out.  */
end_comment

begin_define
define|#
directive|define
name|PUT_SDB_BLOCK_START
parameter_list|(
name|LINE
parameter_list|)
define|\
value|do {							\   extern FILE *asm_out_text_file;			\   fprintf (asm_out_text_file,				\ 	   "$Lb%d:\n\t#.begin\t$Lb%d\t%d\n",		\ 	   sdb_label_count,				\ 	   sdb_label_count,				\ 	   (LINE));					\   sdb_label_count++;					\ } while (0)
end_define

begin_define
define|#
directive|define
name|PUT_SDB_BLOCK_END
parameter_list|(
name|LINE
parameter_list|)
define|\
value|do {							\   extern FILE *asm_out_text_file;			\   fprintf (asm_out_text_file,				\ 	   "$Le%d:\n\t#.bend\t$Le%d\t%d\n",		\ 	   sdb_label_count,				\ 	   sdb_label_count,				\ 	   (LINE));					\   sdb_label_count++;					\ } while (0)
end_define

begin_define
define|#
directive|define
name|PUT_SDB_FUNCTION_START
parameter_list|(
name|LINE
parameter_list|)
end_define

begin_define
define|#
directive|define
name|PUT_SDB_FUNCTION_END
parameter_list|(
name|LINE
parameter_list|)
end_define

begin_define
define|#
directive|define
name|PUT_SDB_EPILOGUE_END
parameter_list|(
name|NAME
parameter_list|)
end_define

begin_define
define|#
directive|define
name|SDB_GENERATE_FAKE
parameter_list|(
name|BUFFER
parameter_list|,
name|NUMBER
parameter_list|)
define|\
value|sprintf ((BUFFER), ".%dfake", (NUMBER));
end_define

begin_escape
end_escape

begin_comment
comment|/* Run-time compilation parameters selecting different hardware subsets.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|target_flags
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Macros used in the machine description to test the flags.  */
end_comment

begin_comment
comment|/* Mips vs. GNU assembler */
end_comment

begin_define
define|#
directive|define
name|TARGET_UNIX_ASM
value|(target_flags& 0x00000001)
end_define

begin_define
define|#
directive|define
name|TARGET_MIPS_AS
value|TARGET_UNIX_ASM
end_define

begin_define
define|#
directive|define
name|TARGET_GAS
value|(TARGET_UNIX_ASM == 0)
end_define

begin_comment
comment|/* Debug Mode */
end_comment

begin_define
define|#
directive|define
name|TARGET_DEBUG_MODE
value|(target_flags& 0x00000002)
end_define

begin_define
define|#
directive|define
name|TARGET_DEBUGA_MODE
value|(target_flags& 0x00000004)
end_define

begin_define
define|#
directive|define
name|TARGET_DEBUGB_MODE
value|(target_flags& 0x00000010)
end_define

begin_define
define|#
directive|define
name|TARGET_DEBUGC_MODE
value|(target_flags& 0x00000020)
end_define

begin_define
define|#
directive|define
name|TARGET_DEBUGD_MODE
value|(target_flags& 0x00000040)
end_define

begin_define
define|#
directive|define
name|TARGET_DEBUGE_MODE
value|(target_flags& 0x00008000)
end_define

begin_comment
comment|/* Reg. Naming in .s ($21 vs. $a0) */
end_comment

begin_define
define|#
directive|define
name|TARGET_NAME_REGS
value|(target_flags& 0x00000008)
end_define

begin_comment
comment|/* addu/subbu vs. add/sub */
end_comment

begin_define
define|#
directive|define
name|TARGET_NOFIXED_OVFL
value|(target_flags& 0x00000080)
end_define

begin_comment
comment|/* Optimize for Sdata/Sbss */
end_comment

begin_define
define|#
directive|define
name|TARGET_GP_OPT
value|(target_flags& 0x00001000)
end_define

begin_define
define|#
directive|define
name|TARGET_GVALUE_MASK
value|(target_flags& 0x00000f00)
end_define

begin_define
define|#
directive|define
name|TARGET_GVALUE
value|(TARGET_GVALUE_MASK>> 8)
end_define

begin_comment
comment|/* Position independent code */
end_comment

begin_define
define|#
directive|define
name|TARGET_PIC
value|(target_flags& 0x00002000)
end_define

begin_define
define|#
directive|define
name|TARGET_PIC_LARGE_OBJECT
value|(target_flags& 0x00004000)
end_define

begin_comment
comment|/* Macro to define tables used to set the flags.    This is a list in braces of pairs in braces,    each pair being { "NAME", VALUE }    where VALUE is the bits to set or minus the bits to clear.    An empty string NAME is used to identify the default VALUE.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_SWITCHES
define|\
value|{ {"mips-as",		  0x00000001},
comment|/* MIPS assembler */
value|\   {"gas",		 -0x00000001},
comment|/* GNU  assembler */
value|\   {"debug",		  0x00000002},
comment|/* Eliminate version in output*/
value|\   {"nodebug",		 -0x00000002},					\   {"debuga",		  0x00000004},
comment|/* don't fold SP pushes into frame */
value|\   {"nodebuga",		 -0x00000004},					\   {"debugb",		  0x00000010},
comment|/* GO_IF_LEGITIMATE_ADDRESS debug */
value|\   {"nodebugb",		 -0x00000010},					\   {"debugc",		  0x00000020},
comment|/* fix frame ptr debug */
value|\   {"nodebugc",		 -0x00000020},					\   {"debugd",		  0x00000040},
comment|/* branch/cc0 debug */
value|\   {"nodebugd",		 -0x00000040},					\   {"rnames",		  0x00000008},
comment|/* Register names like $a0 */
value|\   {"nornames",		 -0x00000008},
comment|/* Register names like $21 */
value|\   {"nofixed-ovfl",	  0x00000080},
comment|/* Use addu and subu */
value|\   {"fixed-ovfl",	 -0x00000080},
comment|/* Use add  and sub */
value|\   {"G0",		  0x00000100},
comment|/* Bit 1 of sdata size */
value|\   {"nG0",		 -0x00000100},					\   {"noG0",		 -0x00000100},					\   {"G1",		  0x00000200},
comment|/* Bit 2 of sdata size */
value|\   {"nG1",		 -0x00000200},					\   {"noG1",		 -0x00000200},					\   {"G2",		  0x00000400},
comment|/* Bit 3 of sdata size */
value|\   {"nG2",		 -0x00000400},					\   {"noG2",		 -0x00000400},					\   {"gpOPT",		  0x00001000},
comment|/* Optimize for global ptr */
value|\   {"ngpOPT",		 -0x00001000},					\   {"nogpOPT",		 -0x00001000},					\   {"pic",		  0x00002000},
comment|/* Position independent code */
value|\   {"npic",		 -0x00002000},					\   {"nopic",		 -0x00002000},					\   {"pic-large-object",	  0x00004000},
comment|/* Don't opt pic local funcs */
value|\   {"nopic-large-object", -0x00004000},					\   {"debuge",		  0x00008000},
comment|/* FUNCTION_ARG debug */
value|\   {"nodebuge",		 -0x00008000},					\   {"",			 TARGET_DEFAULT}}
end_define

begin_comment
comment|/* Default target_flags if no switches specified (-mmips-as, -mnofixed-ovfl,    -G0, -G1 [same as -G 8]).  OSF/1 does not set -mmips-as, and sets -G 0. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|OSF_OS
end_ifndef

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|0x00000381
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|0x00000080
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Default GVALUE  (data item size threshold for selection of Sdata/data)    is computed : GVALUE ==  ( ((i=G0+2*G1+4*G2)< 6) 				        ? 1<<i 					: 1<< (i+3)) */
end_comment

begin_escape
end_escape

begin_comment
comment|/* Target machine storage layout */
end_comment

begin_comment
comment|/* Define this if most significant bit is lowest numbered    in instructions that operate on numbered bit-fields. */
end_comment

begin_comment
comment|/* #define BITS_BIG_ENDIAN */
end_comment

begin_comment
comment|/* Define this if most significant byte of a word is the lowest numbered. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DECSTATION
end_ifndef

begin_define
define|#
directive|define
name|BYTES_BIG_ENDIAN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define this if most significant word of a multiword number is numbered. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DECSTATION
end_ifndef

begin_define
define|#
directive|define
name|WORDS_BIG_ENDIAN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define macros to easily access the most and least significant words    without a lot of #ifdef's.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|WORDS_BIG_ENDIAN
end_ifdef

begin_define
define|#
directive|define
name|MOST_SIGNIFICANT_WORD
value|0
end_define

begin_define
define|#
directive|define
name|LEAST_SIGNIFICANT_WORD
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MOST_SIGNIFICANT_WORD
value|1
end_define

begin_define
define|#
directive|define
name|LEAST_SIGNIFICANT_WORD
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Number of bits in an addressible storage unit */
end_comment

begin_define
define|#
directive|define
name|BITS_PER_UNIT
value|8
end_define

begin_comment
comment|/* Width in bits of a "word", which is the contents of a machine register.    Note that this is not necessarily the width of data type `int';    if using 16-bit ints on a 68000, this would still be 32.    But on a machine with 16-bit registers, this would be 16.  */
end_comment

begin_define
define|#
directive|define
name|BITS_PER_WORD
value|32
end_define

begin_comment
comment|/* Width of a word, in units (bytes).  */
end_comment

begin_define
define|#
directive|define
name|UNITS_PER_WORD
value|4
end_define

begin_comment
comment|/* Width in bits of a pointer.    See also the macro `Pmode' defined below.  */
end_comment

begin_define
define|#
directive|define
name|POINTER_SIZE
value|32
end_define

begin_comment
comment|/* Allocation boundary (in *bits*) for storing pointers in memory.  */
end_comment

begin_define
define|#
directive|define
name|POINTER_BOUNDARY
value|32
end_define

begin_comment
comment|/* Allocation boundary (in *bits*) for storing arguments in argument list.  */
end_comment

begin_define
define|#
directive|define
name|PARM_BOUNDARY
value|32
end_define

begin_comment
comment|/* Give parms extra alignment, up to this much, if their types want it.  */
end_comment

begin_define
define|#
directive|define
name|MAX_PARM_BOUNDARY
value|64
end_define

begin_comment
comment|/* Allocation boundary (in *bits*) for the code of a function.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_BOUNDARY
value|32
end_define

begin_comment
comment|/* Alignment of field after `int : 0' in a structure.  */
end_comment

begin_define
define|#
directive|define
name|EMPTY_FIELD_BOUNDARY
value|32
end_define

begin_comment
comment|/* Every structure's size must be a multiple of this.  */
end_comment

begin_define
define|#
directive|define
name|STRUCTURE_SIZE_BOUNDARY
value|8
end_define

begin_comment
comment|/* There is no point aligning anything to a rounder boundary than this.  */
end_comment

begin_define
define|#
directive|define
name|BIGGEST_ALIGNMENT
value|64
end_define

begin_comment
comment|/* Define this if move instructions will actually fail to work    when given unaligned data.  */
end_comment

begin_define
define|#
directive|define
name|STRICT_ALIGNMENT
end_define

begin_comment
comment|/* Define this macro if an argument declared as `char' or `short' in a    prototype should actually be passed as an `int'.  In addition to    avoiding errors in certain cases of mismatch, it also makes for    better code on certain machines. */
end_comment

begin_define
define|#
directive|define
name|PROMOTE_PROTOTYPES
end_define

begin_escape
end_escape

begin_comment
comment|/* Standard register usage.  */
end_comment

begin_comment
comment|/* Number of actual hardware registers.    The hardware registers are assigned numbers for the compiler    from 0 to just below FIRST_PSEUDO_REGISTER.    All registers that the compiler knows about must be given numbers,    even those that are not normally considered general registers.  */
end_comment

begin_define
define|#
directive|define
name|FIRST_PSEUDO_REGISTER
value|64
end_define

begin_comment
comment|/* 1 for registers that have pervasive standard uses    and are not available for the register allocator.     On the MIPS, see conventions, page D-2     I have chosen not to  take Multiply/Divide HI,LO or PC into    account.  */
end_comment

begin_define
define|#
directive|define
name|FIXED_REGISTERS
value|{1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,\ 		         0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1,\ 		         0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,\ 		         0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0	\ }
end_define

begin_comment
comment|/* 1 for registers not available across function calls.    These must include the FIXED_REGISTERS and also any    registers that can be used without being saved.    The latter must include the registers where values are returned    and the register where structure-value addresses are passed.    Aside from that, you can include as many other registers as you like.  */
end_comment

begin_define
define|#
directive|define
name|CALL_USED_REGISTERS
value|{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,\ 		             0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1,\ 		             1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,\ 		             1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0\ }
end_define

begin_comment
comment|/* Internal macros to classify a register number as to whether it's a    general purpose register or a floating point register.  The macro    FP_CALL_REG_P also allows registers $4 and $6 as floating point    registers to pass floating point as per MIPS spec. */
end_comment

begin_define
define|#
directive|define
name|GP_REG_FIRST
value|0
end_define

begin_define
define|#
directive|define
name|GP_REG_LAST
value|31
end_define

begin_define
define|#
directive|define
name|GP_REG_NUM
value|(GP_REG_LAST - GP_REG_FIRST + 1)
end_define

begin_define
define|#
directive|define
name|FP_REG_FIRST
value|32
end_define

begin_define
define|#
directive|define
name|FP_REG_LAST
value|63
end_define

begin_define
define|#
directive|define
name|FP_REG_NUM
value|(FP_REG_LAST - FP_REG_FIRST + 1)
end_define

begin_define
define|#
directive|define
name|GP_REG_P
parameter_list|(
name|REGNO
parameter_list|)
value|((unsigned) ((REGNO) - GP_REG_FIRST)< GP_REG_NUM)
end_define

begin_define
define|#
directive|define
name|FP_REG_P
parameter_list|(
name|REGNO
parameter_list|)
value|((unsigned) ((REGNO) - FP_REG_FIRST)< FP_REG_NUM)
end_define

begin_define
define|#
directive|define
name|FP_CALL_REG_P
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|(FP_REG_P (REGNO)						\    || (REGNO) == (4 + GP_REG_FIRST)				\    || (REGNO) == (6 + GP_REG_FIRST))
end_define

begin_comment
comment|/* Return number of consecutive hard regs needed starting at reg REGNO    to hold something of mode MODE.    This is ordinarily the length in words of a value of mode MODE    but can be less for certain modes in special long registers.     On the MIPS, all general registers are one word long. I have chosen to    use Floating point register pairs.  */
end_comment

begin_define
define|#
directive|define
name|HARD_REGNO_NREGS
parameter_list|(
name|REGNO
parameter_list|,
name|MODE
parameter_list|)
define|\
value|((MODE == SFmode) ? 2 :						\   ((GET_MODE_SIZE (MODE) + UNITS_PER_WORD - 1) / UNITS_PER_WORD))
end_define

begin_comment
comment|/* Value is 1 if hard register REGNO can hold a value of machine-mode MODE.    On the MIPS, all general registers can hold all  modes, except    FLOATING POINT.  */
end_comment

begin_define
define|#
directive|define
name|HARD_REGNO_MODE_OK
parameter_list|(
name|REGNO
parameter_list|,
name|MODE
parameter_list|)
define|\
value|((GET_MODE_CLASS (MODE) == MODE_INT || MODE == VOIDmode)		\ 	? (GP_REG_P (REGNO))						\ 	: (GET_MODE_CLASS (MODE) == MODE_FLOAT)				\ 		?  (((REGNO)& 1) == 0&& FP_CALL_REG_P (REGNO))	\ 		: 0)
end_define

begin_comment
unit|\
comment|/* Value is 1 if it is a good idea to tie two pseudo registers    when one has mode MODE1 and one has mode MODE2.    If HARD_REGNO_MODE_OK could produce different values for MODE1 and MODE2,    for any hard reg, then this must be 0 for correct output.  */
end_comment

begin_define
define|#
directive|define
name|MODES_TIEABLE_P
parameter_list|(
name|MODE1
parameter_list|,
name|MODE2
parameter_list|)
define|\
value|(   ((MODE1) == SFmode || (MODE1) == DFmode)				\    == ((MODE2) == SFmode || (MODE2) == DFmode))
end_define

begin_comment
comment|/* MIPS pc is apparently not overloaded on a register.  */
end_comment

begin_comment
comment|/* #define PC_REGNUM 15                                 */
end_comment

begin_comment
comment|/* Register to use for pushing function arguments.  */
end_comment

begin_define
define|#
directive|define
name|STACK_POINTER_REGNUM
value|29
end_define

begin_comment
comment|/* Offset from the stack pointer to the first available location.  */
end_comment

begin_define
define|#
directive|define
name|STACK_POINTER_OFFSET
value|0
end_define

begin_comment
comment|/* Base register for access to local variables of the function.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_POINTER_REGNUM
value|30
end_define

begin_comment
comment|/* Value should be nonzero if functions must have frame pointers.    Zero means the frame pointer need not be set up (and parms    may be accessed via the stack pointer) in functions that seem suitable.    This is computed in `reload', in reload1.c.     At present this is required if we are not a leaf procedure.  This    is because the .frame directive requires a register that does not    change throughout the procedure call, and until stack pushes are    folded into the initial stack allocation, we need an unvarying fp.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_POINTER_REQUIRED
value|(stack_args_pushed> 0)
end_define

begin_comment
comment|/* Base register for access to arguments of the function.  */
end_comment

begin_define
define|#
directive|define
name|ARG_POINTER_REGNUM
value|FRAME_POINTER_REGNUM
end_define

begin_comment
comment|/* Register in which static-chain is passed to a function.  */
end_comment

begin_define
define|#
directive|define
name|STATIC_CHAIN_REGNUM
value|2
end_define

begin_comment
comment|/* Register in which address to store a structure value    is passed to a function.  */
end_comment

begin_define
define|#
directive|define
name|STRUCT_VALUE_REGNUM
value|4
end_define

begin_comment
comment|/* Mips registers used in prologue/epilogue code when the stack frame    is larger than 32K bytes.  These registers must come from the    scratch register set, and not used for passing and returning    arguments and any other information used in the calling sequence    (such as pic).  */
end_comment

begin_define
define|#
directive|define
name|MIPS_TEMP1_REGNUM
value|8
end_define

begin_define
define|#
directive|define
name|MIPS_TEMP2_REGNUM
value|9
end_define

begin_comment
comment|/* Define NO_FUNCTION_CSE if it is as good or better to call a constant    function address than to call an address kept in a register.  */
end_comment

begin_define
define|#
directive|define
name|NO_FUNCTION_CSE
end_define

begin_escape
end_escape

begin_comment
comment|/* Define the classes of registers for register constraints in the    machine description.  Also define ranges of constants.     One of the classes must always be named ALL_REGS and include all hard regs.    If there is more than one class, another class must be named NO_REGS    and contain no registers.     The name GENERAL_REGS must be the name of a class (or an alias for    another name such as ALL_REGS).  This is the class of registers    that is allowed by "g" or "r" in a register constraint.    Also, registers outside this class are allocated only when    instructions express preferences for them.     The classes must be numbered in nondecreasing order; that is,    a larger-numbered class must never be contained completely    in a smaller-numbered class.     For any two classes, it is very desirable that there be another    class that represents their union.  */
end_comment

begin_comment
comment|/* The MIPS has general and floating point registers.  */
end_comment

begin_enum
enum|enum
name|reg_class
block|{
name|NO_REGS
block|,
name|GR_REGS
block|,
name|FP_REGS
block|,
name|ALL_REGS
block|,
name|LIM_REG_CLASSES
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|N_REG_CLASSES
value|(int) LIM_REG_CLASSES
end_define

begin_define
define|#
directive|define
name|GENERAL_REGS
value|GR_REGS
end_define

begin_comment
comment|/* Give names of register classes as strings for dump file.   */
end_comment

begin_define
define|#
directive|define
name|REG_CLASS_NAMES
define|\
value|{"NO_REGS", "GR_REGS", "FP_REGS", "ALL_REGS" }
end_define

begin_comment
comment|/* Define which registers fit in which classes.    This is an initializer for a vector of HARD_REG_SET    of length N_REG_CLASSES.  */
end_comment

begin_define
define|#
directive|define
name|REG_CLASS_CONTENTS
value|{{0x00000000, 0x00000000},			\                             {0xffffffff, 0x00000000},			\                             {0x00000000, 0xffffffff},			\ 			    {0xffffffff, 0xffffffff}}
end_define

begin_comment
comment|/* The same information, inverted:    Return the class number of the smallest class containing    reg number REGNO.  This could be a conditional expression    or could index an array.  */
end_comment

begin_define
define|#
directive|define
name|REGNO_REG_CLASS
parameter_list|(
name|REGNO
parameter_list|)
value|((FP_REG_P (REGNO)) ? FP_REGS : GR_REGS)
end_define

begin_comment
comment|/* Define a table that lets us find quickly all the reg classes    containing a given one.  This is the initializer for an    N_REG_CLASSES x N_REG_CLASSES array of reg class codes.    Row N is a sequence containing all the class codes for    classes that contain all the regs in class N.  Each row    contains no duplicates, and is terminated by LIM_REG_CLASSES.  */
end_comment

begin_comment
comment|/* We give just a dummy for the first element, which is for NO_REGS.  */
end_comment

begin_comment
comment|/* #define REG_CLASS_SUPERCLASSES  {{LIM_REG_CLASSES},			\   {GR_REGS,ALL_REGS,LIM_REG_CLASSES},					\   {FP_REGS,ALL_REGS,LIM_REG_CLASSES},					\   {ALL_REGS,LIM_REG_CLASSES}						\ } */
end_comment

begin_comment
comment|/* We give just a dummy for the first element, which is for NO_REGS.  */
end_comment

begin_define
define|#
directive|define
name|REG_CLASS_SUPERCLASSES
value|{{LIM_REG_CLASSES},			\   {ALL_REGS,LIM_REG_CLASSES},						\   {ALL_REGS,LIM_REG_CLASSES},						\   {LIM_REG_CLASSES}							\ }
end_define

begin_comment
comment|/* The inverse relationship:    for each class, a list of all reg classes contained in it.  */
end_comment

begin_define
define|#
directive|define
name|REG_CLASS_SUBCLASSES
define|\
value|{{LIM_REG_CLASSES},							\   {GR_REGS,LIM_REG_CLASSES},						\   {FP_REGS,LIM_REG_CLASSES},\   {GR_REGS, FP_REGS, ALL_REGS, LIM_REG_CLASSES}\ }
end_define

begin_comment
comment|/* Define a table that lets us find quickly the class    for the subunion of any two classes.     We say "subunion" because the result need not be exactly    the union; it may instead be a subclass of the union    (though the closer to the union, the better).    But if it contains anything beyond union of the two classes,    you will lose!     This is an initializer for an N_REG_CLASSES x N_REG_CLASSES    array of reg class codes.  The subunion of classes C1 and C2    is just element [C1, C2].  */
end_comment

begin_define
define|#
directive|define
name|REG_CLASS_SUBUNION
define|\
value|{{NO_REGS,  GR_REGS,   FP_REGS,  ALL_REGS},				\  {GR_REGS,  GR_REGS,   ALL_REGS, ALL_REGS},				\  {FP_REGS,  ALL_REGS,  FP_REGS,  ALL_REGS},				\  {ALL_REGS, ALL_REGS,  ALL_REGS, ALL_REGS}}
end_define

begin_comment
comment|/* The class value for index registers, and the one for base regs.  */
end_comment

begin_define
define|#
directive|define
name|INDEX_REG_CLASS
value|GR_REGS
end_define

begin_define
define|#
directive|define
name|BASE_REG_CLASS
value|GR_REGS
end_define

begin_escape
end_escape

begin_comment
comment|/* REGISTER AND CONSTANT CLASSES 				 */
end_comment

begin_comment
comment|/* Get reg_class from a letter such as appears in the machine description.  */
end_comment

begin_comment
comment|/* DEFINED REGISTER CLASSES: 				** 				** 'f'     : Floating point registers 				** 'y'     : General register when used to 				**           transfer chunks of Floating point 				**           with mfc1 mtc1 insn 				 */
end_comment

begin_define
define|#
directive|define
name|REG_CLASS_FROM_LETTER
parameter_list|(
name|C
parameter_list|)
define|\
value|((C) == 'f' ? FP_REGS:						\      (C) == 'y' ? GR_REGS:NO_REGS)
end_define

begin_comment
comment|/* The letters I, J, K, L and M in a register constraint string    can be used to stand for particular ranges of immediate operands.    This macro defines what the ranges are.    C is the letter, and VALUE is a constant value.    Return 1 if VALUE is in the range specified by C.  */
end_comment

begin_comment
comment|/*   For MIPS, `I' is used for the range of constants an arithmetic insn                    can actually contain (16 bits signed integers).                `J' is used for the range which is just zero (since that is 	           available as $R0). 	       `K' is used for the range of constants a logical insn 	           can actually contain (16 bit zero-extended integers). */
end_comment

begin_define
define|#
directive|define
name|SMALL_INT
parameter_list|(
name|X
parameter_list|)
value|((unsigned) (INTVAL (X) + 0x8000)< 0x10000)
end_define

begin_define
define|#
directive|define
name|SMALL_INT_UNSIGNED
parameter_list|(
name|X
parameter_list|)
value|((unsigned) (INTVAL (X))< 0x10000)
end_define

begin_define
define|#
directive|define
name|CONST_OK_FOR_LETTER_P
parameter_list|(
name|VALUE
parameter_list|,
name|C
parameter_list|)
define|\
value|((C) == 'I' ? (unsigned) ((VALUE) + 0x8000)< 0x10000			\    : (C) == 'J' ? (VALUE) == 0						\    : (C) == 'K' ? (unsigned) (VALUE)< 0x10000				\    : 0)
end_define

begin_comment
comment|/* Similar, but for floating constants, and defining letters G and H.    Here VALUE is the CONST_DOUBLE rtx itself.  */
end_comment

begin_comment
comment|/* DEFINED FLOATING CONSTANT CLASSES: 				** 				** 'G'     : Floating point 0 				 */
end_comment

begin_define
define|#
directive|define
name|CONST_DOUBLE_OK_FOR_LETTER_P
parameter_list|(
name|VALUE
parameter_list|,
name|C
parameter_list|)
define|\
value|((C) == 'G'&& XINT (VALUE, 0) == 0&& XINT (VALUE, 1) == 0)
end_define

begin_comment
comment|/* Given an rtx X being reloaded into a reg required to be    in class CLASS, return the class of reg to actually use.    In general this is just CLASS; but on some machines    in some cases it is preferable to use a more restrictive class.  */
end_comment

begin_define
define|#
directive|define
name|PREFERRED_RELOAD_CLASS
parameter_list|(
name|X
parameter_list|,
name|CLASS
parameter_list|)
define|\
value|(((GET_MODE(X) == SFmode) || (GET_MODE(X) == DFmode))? FP_REGS  :	\      ((GET_MODE(X) == VOIDmode) ? GR_REGS :(CLASS)))
end_define

begin_comment
comment|/* Same but Mode has been extracted already */
end_comment

begin_define
define|#
directive|define
name|PREFERRED_RELOAD_CLASS_FM
parameter_list|(
name|X
parameter_list|,
name|CLASS
parameter_list|)
define|\
value|((((X) == SFmode) || ((X) == DFmode))? FP_REGS  :			\      (((X) == VOIDmode) ? GR_REGS :(CLASS)))
end_define

begin_comment
comment|/* Return the maximum number of consecutive registers    needed to represent mode MODE in a register of class CLASS.  */
end_comment

begin_define
define|#
directive|define
name|CLASS_MAX_NREGS
parameter_list|(
name|CLASS
parameter_list|,
name|MODE
parameter_list|)
define|\
value|((((MODE) == DFmode) || ((MODE) == SFmode)) ? 2			\   : ((MODE) == VOIDmode)? ((CLASS) == FP_REGS ? 2 :1)			\   : ((GET_MODE_SIZE (MODE) + UNITS_PER_WORD - 1) / UNITS_PER_WORD))
end_define

begin_escape
end_escape

begin_comment
comment|/* Stack layout; function entry, exit and calling.  */
end_comment

begin_comment
comment|/* Define this if pushing a word on the stack    makes the stack pointer a smaller address.  */
end_comment

begin_define
define|#
directive|define
name|STACK_GROWS_DOWNWARD
end_define

begin_comment
comment|/* Define this if the nominal address of the stack frame    is at the high-address end of the local variables;    that is, each additional local variable allocated    goes at a more negative offset in the frame.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_GROWS_DOWNWARD
end_define

begin_comment
comment|/* Offset within stack frame to start allocating local variables at.    If FRAME_GROWS_DOWNWARD, this is the offset to the END of the    first local allocated.  Otherwise, it is the offset to the BEGINNING    of the first local allocated.  */
end_comment

begin_define
define|#
directive|define
name|STARTING_FRAME_OFFSET
value|-8
end_define

begin_comment
comment|/* If we generate an insn to push BYTES bytes,    this says how many the stack pointer really advances by.    On the vax, sp@- in a byte insn really pushes a word.  */
end_comment

begin_comment
comment|/* #define PUSH_ROUNDING(BYTES) 0 */
end_comment

begin_comment
comment|/* Offset of first parameter from the argument pointer register value.  */
end_comment

begin_define
define|#
directive|define
name|FIRST_PARM_OFFSET
parameter_list|(
name|FNDECL
parameter_list|)
value|0
end_define

begin_comment
comment|/* Offset from top-of-stack address to location to store the    function parameter if it can't go in a register.    Addresses for following parameters are computed relative to this one.     It also has the effect of counting register arguments in the total    argument size. */
end_comment

begin_define
define|#
directive|define
name|FIRST_PARM_CALLER_OFFSET
parameter_list|(
name|FNDECL
parameter_list|)
value|0
end_define

begin_comment
comment|/* When a parameter is passed in a register, stack space is still    allocated for it.  For the MIPS, stack space must be allocated, cf    Asm Lang Prog Guide page 7-8.     BEWARE that some space is also allocated for non existing arguments    in register. In case an argument list is of form GF used registers    are a0 (a2,a3), but we should push over a1...  */
end_comment

begin_define
define|#
directive|define
name|REG_PARM_STACK_SPACE
end_define

begin_comment
comment|/* Align stack frames on 64 bits (Double Word ).  */
end_comment

begin_define
define|#
directive|define
name|STACK_BOUNDARY
value|64
end_define

begin_escape
end_escape

begin_comment
comment|/* Standard GCC stack related variables that we reference.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|optimize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|may_call_alloca
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|current_function_calls_alloca
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|frame_pointer_needed
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|flag_omit_frame_pointer
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* MIPS external variables defined in out-mips.c.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|reg_numchar
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* register names as $r2, etc. */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|current_function_name
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current function being compiled */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|num_source_filenames
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current .file # */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|inside_function
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* != 0 if inside of a function */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|stack_args_pushed
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* max bytes pushed for calls */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|stack_args_preallocated
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # bytes for args preallocated */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|sdb_label_count
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* block start/end next label # */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|mips_section_threshold
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # bytes of data/sdata cutoff */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|sym_lineno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* sgi next label # for each stmt */
end_comment

begin_comment
comment|/* Make sure 16 bytes are always allocated on the stack.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|STACK_ARGS_ADJUST
end_ifndef

begin_define
define|#
directive|define
name|STACK_ARGS_ADJUST
parameter_list|(
name|SIZE
parameter_list|)
define|\
value|{									\   if (SIZE.constant< 16)						\     SIZE.constant = 16;							\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/* Value is 1 if returning from a function call automatically    pops the arguments described by the number-of-args field in the call.    FUNTYPE is the data type of the function (as a tree),    or for a library call it is an identifier node for the subroutine name.  */
end_comment

begin_define
define|#
directive|define
name|RETURN_POPS_ARGS
parameter_list|(
name|FUNTYPE
parameter_list|)
value|0
end_define

begin_comment
comment|/* Symbolic macros for the registers used to return integer and floating    point values.  */
end_comment

begin_define
define|#
directive|define
name|GP_RETURN
value|2
end_define

begin_define
define|#
directive|define
name|FP_RETURN
value|32
end_define

begin_comment
comment|/* Symbolic macros for the first/last argument registers.  */
end_comment

begin_define
define|#
directive|define
name|GP_ARG_FIRST
value|4
end_define

begin_define
define|#
directive|define
name|GP_ARG_LAST
value|7
end_define

begin_define
define|#
directive|define
name|FP_ARG_FIRST
value|44
end_define

begin_define
define|#
directive|define
name|FP_ARG_LAST
value|47
end_define

begin_define
define|#
directive|define
name|MAX_ARGS_IN_REGISTERS
value|4
end_define

begin_comment
comment|/* Define how to find the value returned by a library function    assuming the value has mode MODE.  */
end_comment

begin_define
define|#
directive|define
name|LIBCALL_VALUE
parameter_list|(
name|MODE
parameter_list|)
define|\
value|gen_rtx (REG, MODE,							\ 	   (GET_MODE_CLASS (MODE) == MODE_FLOAT)			\ 		? FP_RETURN						\ 		: GP_RETURN)
end_define

begin_comment
comment|/* Define how to find the value returned by a function.    VALTYPE is the data type of the value (as a tree).    If the precise function being called is known, FUNC is its FUNCTION_DECL;    otherwise, FUNC is 0.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_VALUE
parameter_list|(
name|VALTYPE
parameter_list|,
name|FUNC
parameter_list|)
value|LIBCALL_VALUE (TYPE_MODE (VALTYPE))
end_define

begin_comment
comment|/* 1 if N is a possible register number for a function value.    On the MIPS, R2 R3 and F0 F2 are the only register thus used.    Currently, R2 and F0 are only implemented  here (C has no complex type)  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_VALUE_REGNO_P
parameter_list|(
name|N
parameter_list|)
value|((N) == GP_RETURN || (N) == FP_RETURN)
end_define

begin_comment
comment|/* 1 if N is a possible register number for function argument passing.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_ARG_REGNO_P
parameter_list|(
name|N
parameter_list|)
value|(((N)>= GP_ARG_FIRST&& (N)<= GP_ARG_LAST)   \ 				 || ((N)>= FP_ARG_FIRST&& (N)<= FP_ARG_LAST \&& (0 == (N) % 2)))
end_define

begin_comment
comment|/* A C expression which can inhibit the returning of certain function    values in registers, based on the type of value.  A nonzero value says    to return the function value in memory, just as large structures are    always returned.  Here TYPE will be a C expression of type    `tree', representing the data type of the value.     Note that values of mode `BLKmode' are returned in memory    regardless of this macro.  Also, the option `-fpcc-struct-return'    takes effect regardless of this macro.  On most systems, it is    possible to leave the macro undefined; this causes a default    definition to be used, whose value is the constant 0.     GCC normally converts 1 byte structures into chars, 2 byte    structs into shorts, and 4 byte structs into ints, and returns    them this way.  Defining the following macro overides this,    to give us MIPS cc compatibility.  */
end_comment

begin_define
define|#
directive|define
name|RETURN_IN_MEMORY
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|((TREE_CODE (TYPE) == RECORD_TYPE) || (TREE_CODE (TYPE) == UNION_TYPE))
end_define

begin_escape
end_escape

begin_comment
comment|/* Define a data type for recording info about an argument list    during the scan of that argument list.  This data type should    hold all necessary information about the function itself    and about the args processed so far, enough to enable macros    such as FUNCTION_ARG to determine where the next arg should go. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|mips_args
block|{
name|int
name|gp_reg_found
decl_stmt|;
name|int
name|arg_number
decl_stmt|;
name|int
name|arg_words
decl_stmt|;
block|}
typedef|*
name|CUMULATIVE_ARGS
typedef|;
end_typedef

begin_comment
comment|/* Initialize a variable CUM of type CUMULATIVE_ARGS    for a call to a function whose data type is FNTYPE.    For a library call, FNTYPE is 0.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|init_cumulative_args
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|INIT_CUMULATIVE_ARGS
parameter_list|(
name|CUM
parameter_list|,
name|FNTYPE
parameter_list|)
define|\
value|do {									\   CUM = (CUMULATIVE_ARGS) alloca (sizeof (*CUM));			\   init_cumulative_args (CUM, FNTYPE);					\ } while (0)
end_define

begin_comment
comment|/* Update the data in CUM to advance over an argument    of mode MODE and data type TYPE.    (TYPE is null for libcalls where that information may not be available.)  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_ARG_ADVANCE
parameter_list|(
name|CUM
parameter_list|,
name|MODE
parameter_list|,
name|TYPE
parameter_list|,
name|NAMED
parameter_list|)
define|\
value|(function_arg_advance(CUM, MODE, TYPE, NAMED))
end_define

begin_function_decl
specifier|extern
name|void
name|function_arg_advance
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Determine where to put an argument to a function.    Value is zero to push the argument on the stack,    or a hard register in which to store the argument.     MODE is the argument's machine mode.    TYPE is the data type of the argument (as a tree).     This is null for libcalls where that information may     not be available.    CUM is a variable of type CUMULATIVE_ARGS which gives info about     the preceding args and about the function being called.    NAMED is nonzero if this argument is a named parameter     (otherwise it is an extra parameter matching an ellipsis).  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|rtx_def
modifier|*
name|function_arg
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|FUNCTION_ARG
parameter_list|(
name|CUM
parameter_list|,
name|MODE
parameter_list|,
name|TYPE
parameter_list|,
name|NAMED
parameter_list|)
define|\
value|(function_arg(CUM, MODE, TYPE, NAMED))
end_define

begin_comment
comment|/* For an arg passed partly in registers and partly in memory,    this is the number of registers used.    For args passed entirely in registers or entirely in memory, zero. */
end_comment

begin_function_decl
specifier|extern
name|int
name|function_arg_partial_nregs
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|FUNCTION_ARG_PARTIAL_NREGS
parameter_list|(
name|CUM
parameter_list|,
name|MODE
parameter_list|,
name|TYPE
parameter_list|,
name|NAMED
parameter_list|)
define|\
value|(function_arg_partial_nregs (CUM, MODE, TYPE, NAMED))
end_define

begin_escape
end_escape

begin_comment
comment|/* This macro generates the assembly code for function entry.    FILE is a stdio stream to output the code to.    SIZE is an int: how many units of temporary storage to allocate.    Refer to the array `regs_ever_live' to determine which registers    to save; `regs_ever_live[I]' is nonzero if register number I    is ever used in the function.  This macro is responsible for    knowing which registers should not be saved even if used.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|function_prologue
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|FUNCTION_PROLOGUE
parameter_list|(
name|FILE
parameter_list|,
name|SIZE
parameter_list|)
value|function_prologue(FILE, SIZE)
end_define

begin_comment
comment|/* This macro generates the assembly code for function exit,    on machines that need it.  If FUNCTION_EPILOGUE is not defined    then individual return instructions are generated for each    return statement.  Args are same as for FUNCTION_PROLOGUE.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|function_epilogue
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|FUNCTION_EPILOGUE
parameter_list|(
name|FILE
parameter_list|,
name|SIZE
parameter_list|)
value|function_epilogue(FILE, SIZE)
end_define

begin_comment
comment|/* Tell prologue and epilogue if Register containing return    address should be saved / restored.  */
end_comment

begin_define
define|#
directive|define
name|MUST_SAVE_REGISTER
parameter_list|(
name|regno
parameter_list|)
define|\
value|((regs_ever_live[regno]&& !call_used_regs[regno]) || \   (regno == FRAME_POINTER_REGNUM&& frame_pointer_needed) || \   (regno == 31&& regs_ever_live[31]))
end_define

begin_comment
comment|/* ALIGN FRAMES on double word boundaries */
end_comment

begin_define
define|#
directive|define
name|AL_ADJUST_ALIGN
parameter_list|(
name|LOC
parameter_list|)
value|(((LOC)+7)& 0xfffffff8)
end_define

begin_escape
end_escape

begin_comment
comment|/* If the memory Address ADDR is relative to the frame pointer,    correct it to be relative to the stack pointer. This is for    when we don't use a frame pointer.    ADDR should be a variable name.  */
end_comment

begin_define
define|#
directive|define
name|FIX_FRAME_POINTER_ADDRESS
parameter_list|(
name|ADDR
parameter_list|,
name|DEPTH
parameter_list|)
define|\
value|{ ADDR = mips_fix_frame_pointer(ADDR, DEPTH); }
end_define

begin_function_decl
specifier|extern
name|struct
name|rtx_def
modifier|*
name|mips_fix_frame_pointer
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Output assembler code to FILE to increment profiler label # LABELNO    for profiling a function entry.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_PROFILER
parameter_list|(
name|FILE
parameter_list|,
name|LABELNO
parameter_list|)
define|\
value|{									\   register char **reg_ptr = (TARGET_NAME_REGS) ? reg_names : reg_numchar; \ 									\   fprintf (FILE, "\t.set\tnoreorder\n");				\   fprintf (FILE, "\t.set\tnoat\n");					\   fprintf (FILE, "\tmove\t%s,%s\t\t# save current return address\n",	\ 	   reg_ptr[1], reg_ptr[31]);					\   fprintf (FILE, "\tjal\t_mcount\n");					\   fprintf (FILE, "\tsubu\t%s,%s,8\t\t# _mcount pops 2 words from  stack\n", \ 	   reg_ptr[STACK_POINTER_REGNUM], reg_ptr[STACK_POINTER_REGNUM]); \   fprintf (FILE, "\t.set\treorder\n");					\   fprintf (FILE, "\t.set\tat\n");					\ }
end_define

begin_comment
comment|/* EXIT_IGNORE_STACK should be nonzero if, when returning from a function,    the stack pointer does not matter.  The value is tested only in    functions that have frame pointers.    No definition is equivalent to always zero.  */
end_comment

begin_define
define|#
directive|define
name|EXIT_IGNORE_STACK
value|1
end_define

begin_escape
end_escape

begin_comment
comment|/* Addressing modes, and classification of registers for them.  */
end_comment

begin_comment
comment|/* #define HAVE_POST_INCREMENT */
end_comment

begin_comment
comment|/* #define HAVE_POST_DECREMENT */
end_comment

begin_comment
comment|/* #define HAVE_PRE_DECREMENT */
end_comment

begin_comment
comment|/* #define HAVE_PRE_INCREMENT */
end_comment

begin_comment
comment|/* These assume that REGNO is a hard or pseudo reg number.    They give nonzero only if REGNO is a hard reg of the suitable class    or a pseudo reg currently allocated to a suitable hard reg.    These definitions are NOT overridden anywhere.  */
end_comment

begin_define
define|#
directive|define
name|REGNO_OK_FOR_INDEX_P
parameter_list|(
name|regno
parameter_list|)
define|\
value|((regno)< FIRST_PSEUDO_REGISTER || reg_renumber[regno]>= 0)
end_define

begin_define
define|#
directive|define
name|REGNO_OK_FOR_BASE_P
parameter_list|(
name|regno
parameter_list|)
define|\
value|((regno)< FIRST_PSEUDO_REGISTER || reg_renumber[regno]>= 0)
end_define

begin_comment
comment|/* The macros REG_OK_FOR..._P assume that the arg is a REG rtx    and check its validity for a certain class.    We have two alternate definitions for each of them.    The usual definition accepts all pseudo regs; the other rejects them all.    The symbol REG_OK_STRICT causes the latter definition to be used.     Most source files want to accept pseudo regs in the hope that    they will get allocated to the class that the insn wants them to be in.    Some source files that are used after register allocation    need to be strict.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|REG_OK_STRICT
end_ifndef

begin_define
define|#
directive|define
name|REG_OK_FOR_INDEX_P
parameter_list|(
name|X
parameter_list|)
value|1
end_define

begin_comment
comment|/* ok if index or pseudo reg */
end_comment

begin_define
define|#
directive|define
name|REG_OK_FOR_BASE_P
parameter_list|(
name|X
parameter_list|)
value|1
end_define

begin_comment
comment|/* ok if base reg. of pseudo reg */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|REG_OK_FOR_INDEX_P
parameter_list|(
name|X
parameter_list|)
value|REGNO_OK_FOR_INDEX_P (REGNO (X))
end_define

begin_define
define|#
directive|define
name|REG_OK_FOR_BASE_P
parameter_list|(
name|X
parameter_list|)
value|REGNO_OK_FOR_BASE_P  (REGNO (X))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/* Maximum number of registers that can appear in a valid memory address.  */
end_comment

begin_define
define|#
directive|define
name|MAX_REGS_PER_ADDRESS
value|1
end_define

begin_comment
comment|/* GO_IF_LEGITIMATE_ADDRESS recognizes an RTL expression    that is a valid memory address for an instruction.    The MODE argument is the machine mode for the MEM expression    that wants to use this address.     The other macros defined here are used only in GO_IF_LEGITIMATE_ADDRESS,    except for CONSTANT_ADDRESS_P which is actually machine-independent.  */
end_comment

begin_comment
comment|/* 1 if X is an address that we could indirect through.  */
end_comment

begin_define
define|#
directive|define
name|INDIRECTABLE_ADDRESS_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(CONSTANT_ADDRESS_P (X)						\    || (GET_CODE (X) == REG&& REG_OK_FOR_BASE_P (X))			\    || (GET_CODE (X) == PLUS						\&& ((xplus0 = XEXP (X, 0)),					\ 	   (xplus1 = XEXP (X, 1)),					\ 	   ((GET_CODE (xplus0) != REG&& GET_CODE (xplus1) == REG)	\ 	    ? ((xplus0 = XEXP (X, 1)), (xplus1 = XEXP (X, 0)))		\ 	    : 0),							\ 	   GET_CODE (xplus0) == REG)					\&& REG_OK_FOR_BASE_P (xplus0)					\&& ((GET_CODE (xplus1) == CONST_INT&& SMALL_INT (xplus1))	\ 	   || (GET_CODE (xplus1) == LABEL_REF)				\ 	   || (GET_CODE (xplus1) == SYMBOL_REF)				\ 	   || (GET_CODE (xplus1) == CONST)				\ 	   || (xplus0 == stack_pointer_rtx				\&& (GET_CODE (xplus1) == CONST || (GET_CODE (xplus1) == SYMBOL_REF))))))
end_define

begin_if
if|#
directive|if
literal|1
end_if

begin_function_decl
specifier|extern
name|void
name|trace
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|GO_PRINTF
parameter_list|(
name|x
parameter_list|)
value|trace(x)
end_define

begin_define
define|#
directive|define
name|GO_DEBUG_RTX
parameter_list|(
name|x
parameter_list|)
value|debug_rtx(x)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GO_PRINTF
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|GO_DEBUG_RTX
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Go to ADDR if X is a valid address not using indexing.    (This much is the easy part.)  */
end_comment

begin_define
define|#
directive|define
name|GO_IF_LEGITIMATE_ADDRESS
parameter_list|(
name|MODE
parameter_list|,
name|X
parameter_list|,
name|ADDR
parameter_list|)
define|\
value|{									\   register rtx xinsn = (X);						\   register rtx xplus0, xplus1;						\ 									\   if (TARGET_DEBUGB_MODE)						\     {									\       GO_PRINTF ("\n==================== GO_IF_LEGITIMATE_ADDRESS\n");	\       GO_DEBUG_RTX (xinsn);						\     }									\ 									\   if (GET_CODE (xinsn) == REG)		goto ADDR;			\   if (INDIRECTABLE_ADDRESS_P (xinsn))   goto ADDR;			\ 									\   if (TARGET_DEBUGB_MODE)						\     GO_PRINTF ("Not a legitimate address\n");				\ }
end_define

begin_define
define|#
directive|define
name|CONSTANT_ADDRESS_P
parameter_list|(
name|X
parameter_list|)
value|CONSTANT_P (X)
end_define

begin_comment
comment|/* Nonzero if the constant value X is a legitimate general operand.    It is given that X satisfies CONSTANT_P or is a CONST_DOUBLE.     At present, GAS doesn't understand li.[sd], so don't allow it    to be generated at present.  Also, the MIPS assembler does not    grok li.d Infinity.  */
end_comment

begin_define
define|#
directive|define
name|LEGITIMATE_CONSTANT_P
parameter_list|(
name|X
parameter_list|)
value|(GET_CODE (X) != CONST_DOUBLE)
end_define

begin_comment
comment|/* Try machine-dependent ways of modifying an illegitimate address    to be legitimate.  If we find one, return the new, valid address.    This macro is used in only one place: `memory_address' in explow.c.     OLDX is the address as it was before break_out_memory_refs was called.    In some cases it is useful to look at this to decide what needs to be done.     MODE and WIN are passed so that this macro can use    GO_IF_LEGITIMATE_ADDRESS.     It is always safe for this macro to do nothing.  It exists to recognize    opportunities to optimize the output.     For the MIPS (so far ..), nothing needs to be done.     ACHTUNG this is actually used by the FLOW analysis to get rid    of statements....  */
end_comment

begin_define
define|#
directive|define
name|LEGITIMIZE_ADDRESS
parameter_list|(
name|X
parameter_list|,
name|OLDX
parameter_list|,
name|MODE
parameter_list|,
name|WIN
parameter_list|)
value|{}
end_define

begin_comment
comment|/* Go to LABEL if ADDR (a legitimate address expression)    has an effect that depends on the machine mode it is used for.  */
end_comment

begin_define
define|#
directive|define
name|GO_IF_MODE_DEPENDENT_ADDRESS
parameter_list|(
name|ADDR
parameter_list|,
name|LABEL
parameter_list|)
value|{}
end_define

begin_escape
end_escape

begin_comment
comment|/* Specify the machine mode that this machine uses    for the index in the tablejump instruction.  */
end_comment

begin_define
define|#
directive|define
name|CASE_VECTOR_MODE
value|SImode
end_define

begin_comment
comment|/* Define this if the tablejump instruction expects the table    to contain offsets from the address of the table.    Do not define this if the table should contain absolute addresses.  */
end_comment

begin_comment
comment|/* #define CASE_VECTOR_PC_RELATIVE */
end_comment

begin_comment
comment|/* Specify the tree operation to be used to convert reals to integers.  */
end_comment

begin_define
define|#
directive|define
name|IMPLICIT_FIX_EXPR
value|FIX_ROUND_EXPR
end_define

begin_comment
comment|/* This is the kind of divide that is easiest to do in the general case.  */
end_comment

begin_define
define|#
directive|define
name|EASY_DIV_EXPR
value|TRUNC_DIV_EXPR
end_define

begin_comment
comment|/* Define this as 1 if `char' should by default be signed; else as 0.  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_SIGNED_CHAR
value|1
end_define

begin_comment
comment|/* Max number of bytes we can move from memory to memory    in one reasonably fast instruction.  */
end_comment

begin_define
define|#
directive|define
name|MOVE_MAX
value|4
end_define

begin_comment
comment|/* Nonzero if access to memory by bytes is slow and undesirable.  */
end_comment

begin_define
define|#
directive|define
name|SLOW_BYTE_ACCESS
value|0
end_define

begin_comment
comment|/* We assume that the store-condition-codes instructions store 0 for false    and some other value for true.  This is the value stored for true.  */
end_comment

begin_define
define|#
directive|define
name|STORE_FLAG_VALUE
value|1
end_define

begin_comment
comment|/* Declarations for condition code stuff.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|compare_collect
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|compare_restore
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Define this if zero-extension is slow (more than one real instruction).  */
end_comment

begin_define
define|#
directive|define
name|SLOW_ZERO_EXTEND
end_define

begin_comment
comment|/* Define if shifts truncate the shift count    which implies one can omit a sign-extension or zero-extension    of a shift count.     Only 5 bits are used in SLLV and SRLV */
end_comment

begin_define
define|#
directive|define
name|SHIFT_COUNT_TRUNCATED
end_define

begin_comment
comment|/* Value is 1 if truncating an integer of INPREC bits to OUTPREC bits    is done just by pretending it is already truncated.  */
end_comment

begin_define
define|#
directive|define
name|TRULY_NOOP_TRUNCATION
parameter_list|(
name|OUTPREC
parameter_list|,
name|INPREC
parameter_list|)
value|1
end_define

begin_comment
comment|/* Specify the machine mode that pointers have.    After generation of rtl, the compiler makes no further distinction    between pointers and any other objects of this machine mode.  */
end_comment

begin_define
define|#
directive|define
name|Pmode
value|SImode
end_define

begin_comment
comment|/* A function address in a call instruction    is a word address (for indexing purposes)    so give the MEM rtx a words's mode.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_MODE
value|SImode
end_define

begin_comment
comment|/* Compute the cost of computing a constant rtl expression RTX    whose rtx-code is CODE.  The body of this macro is a portion    of a switch statement.  If the code is computed here,    return it with a return statement.  Otherwise, break from the switch.  */
end_comment

begin_define
define|#
directive|define
name|CONST_COSTS
parameter_list|(
name|RTX
parameter_list|,
name|CODE
parameter_list|)
define|\
value|case CONST_INT:							\
comment|/* Constant zero is super cheap due to register 0.  */
value|\     if (RTX == const0_rtx) return 0;					\     if ((INTVAL (RTX)< 0x7fff)&& (- INTVAL(RTX)< 0x7fff)) return 1;	\   case CONST:								\   case LABEL_REF:							\   case SYMBOL_REF:							\     return 3;								\   case CONST_DOUBLE:							\     return 5;
end_define

begin_comment
comment|/* Used in by the peephole code.  */
end_comment

begin_define
define|#
directive|define
name|additive_op
parameter_list|(
name|op
parameter_list|,
name|mode
parameter_list|)
value|(GET_CODE (op) == PLUS || GET_CODE (op) == MINUS)
end_define

begin_escape
end_escape

begin_comment
comment|/* Tell final.c how to eliminate redundant test instructions.  */
end_comment

begin_comment
comment|/* Here we define machine-dependent flags and fields in cc_status    (see `conditions.h').  No extra ones are needed for the vax.  */
end_comment

begin_comment
comment|/* Tell final.c how to eliminate redundant test instructions.  */
end_comment

begin_escape
end_escape

begin_comment
comment|/* Tell final.c how to eliminate redundant test instructions.  */
end_comment

begin_comment
comment|/* Here we define machine-dependent flags and fields in cc_status    (see `conditions.h').  No extra ones are needed for the vax.  */
end_comment

begin_comment
comment|/* Store in cc_status the expressions    that the condition codes will describe    after execution of an instruction whose pattern is EXP.    Do not alter them if the instruction would not alter the cc's.  */
end_comment

begin_define
define|#
directive|define
name|NOTICE_UPDATE_CC
parameter_list|(
name|EXP
parameter_list|,
name|INSN
parameter_list|)
define|\
value|CC_STATUS_INIT;
end_define

begin_comment
comment|/* Here we define machine-dependent flags and fields in cc_status    (see `conditions.h').   */
end_comment

begin_escape
end_escape

begin_comment
comment|/* Control the assembler format that we output.  */
end_comment

begin_comment
comment|/* Output at beginning of assembler file.    If we are optimizing to use the global pointer, create a temporary    file to hold all of the text stuff, and write it out to the end.    This is needed because the MIPS assembler is evidently one pass,    and if it hasn't seen the relevant .comm/.lcomm/.extern/.sdata    declaration when the code is processed, it generates a two    instruction sequence.  */
end_comment

begin_define
define|#
directive|define
name|ASM_FILE_START
parameter_list|(
name|STREAM
parameter_list|)
define|\
value|{									\   extern FILE *asm_out_text_file, *asm_out_data_file;			\   extern FILE *tmpfile ();						\   if (TARGET_NAME_REGS)							\     fprintf (STREAM, "#include<regdef.h>\n");				\   ASM_OUTPUT_SOURCE_FILENAME (STREAM, main_input_filename);		\   print_options(STREAM);						\   data_section ();
comment|/* put gcc_compiled. in data, not text*/
value|\   if (TARGET_GP_OPT)							\     {									\       asm_out_data_file = STREAM;					\       asm_out_text_file = tmpfile ();					\       if (!asm_out_text_file)						\ 	pfatal_with_name ("Can't open temporary file with tmpfile");	\     }									\   else									\     asm_out_data_file = asm_out_text_file = STREAM;			\ }
end_define

begin_comment
comment|/* Output to assembler file text saying following lines    may contain character constants, extra white space, comments, etc.  */
end_comment

begin_define
define|#
directive|define
name|ASM_APP_ON
value|" #APP\n"
end_define

begin_comment
comment|/* Output to assembler file text saying following lines    no longer contain unusual constructs.  */
end_comment

begin_define
define|#
directive|define
name|ASM_APP_OFF
value|" #NO_APP\n"
end_define

begin_comment
comment|/* How to refer to registers in assembler output.    This sequence is indexed by compiler's hard-register-number (see above).  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_NAMES
define|\
value|{"$0", "at", "v0", "v1", "a0", "a1", "a2", "a3", "t0",			\  "t1", "t2", "t3", "t4", "t5", "t6", "t7","s0",				\  "s1","s2","s3","s4","s5","s6","s7","t8","t9",				\  "k0","k1","gp","sp","fp","ra",						\  "$f0","$f1","$f2","$f3","$f4","$f5","$f6","$f7","$f8","$f9",		\ "$f10","$f11","$f12","$f13","$f14","$f15","$f16","$f17","$f18","$f19",	\ "$f20","$f21","$f22","$f23","$f24","$f25","$f26","$f27","$f28","$f29",	\ "$f30","$f31"								\ }
end_define

begin_define
define|#
directive|define
name|REGISTER_NUMCHAR
define|\
value|{									\ "$0","$1","$2","$3","$4","$5","$6","$7","$8","$9",			\ "$10","$11","$12","$13","$14","$15","$16","$17","$18","$19",		\ "$20","$21","$22","$23","$24","$25","$26","$27","$28","$sp",		\ "$fp","$31",								\ "$f0","$f1","$f2","$f3","$f4","$f5","$f6","$f7","$f8","$f9",		\ "$f10","$f11","$f12","$f13","$f14","$f15","$f16","$f17","$f18","$f19",	\ "$f20","$f21","$f22","$f23","$f24","$f25","$f26","$f27","$f28","$f29",	\ "$f30","$f31"								\ }
end_define

begin_define
define|#
directive|define
name|REG_NAME
parameter_list|(
name|reg
parameter_list|)
value|(TARGET_NAME_REGS ? reg_names[reg] : reg_numchar[reg])
end_define

begin_comment
comment|/* Define results of standard character escape sequences.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_BELL
value|007
end_define

begin_define
define|#
directive|define
name|TARGET_BS
value|010
end_define

begin_define
define|#
directive|define
name|TARGET_TAB
value|011
end_define

begin_define
define|#
directive|define
name|TARGET_NEWLINE
value|012
end_define

begin_define
define|#
directive|define
name|TARGET_VT
value|013
end_define

begin_define
define|#
directive|define
name|TARGET_FF
value|014
end_define

begin_define
define|#
directive|define
name|TARGET_CR
value|015
end_define

begin_comment
comment|/* Print an instruction operand X on file FILE.    CODE is the code from the %-spec that requested printing this operand;    if `%z3' was used to print operand 3, then CODE is 'z'.    CODE is used as follows:      LIST OF PRINT OPERAND CODES:  	'x'  X is CONST_INT, prints 16 bits in hex format. 	'd'  output integer constant in decimal, 	':'  Prints an 'u' if flag -mnofixed-ovfl (for addu vs. add)  */
end_comment

begin_define
define|#
directive|define
name|PRINT_OPERAND_PUNCT_VALID_P
parameter_list|(
name|CODE
parameter_list|)
define|\
value|((CODE) == ':')
end_define

begin_define
define|#
directive|define
name|PRINT_OPERAND
parameter_list|(
name|FILE
parameter_list|,
name|X
parameter_list|,
name|CODE
parameter_list|)
define|\
value|{									\   if ((CODE) == ':')							\     {									\       if (TARGET_NOFIXED_OVFL)						\ 	fprintf(FILE,"u");						\     }									\ 									\   else if (GET_CODE (X) == REG)						\     {									\       int regnum = REGNO (X);						\ 									\       if (CODE == 'M')							\ 	regnum += MOST_SIGNIFICANT_WORD;				\       else if (CODE == 'L')						\ 	regnum += LEAST_SIGNIFICANT_WORD;				\       else if (CODE == 'D')						\ 	regnum++;							\ 									\       fprintf (FILE, "%s",						\ 	       ((TARGET_NAME_REGS) ? reg_names : reg_numchar)[regnum]); \     }									\ 									\   else if (GET_CODE (X) == MEM)						\     output_address (XEXP (X, 0));					\ 									\   else if (GET_CODE (X) == CONST_DOUBLE)				\     {									\       union { double d; int i[2]; } u;					\       u.i[0] = CONST_DOUBLE_LOW (X);					\       u.i[1] = CONST_DOUBLE_HIGH (X);					\       if (GET_MODE (X) == SFmode)					\ 	{								\ 	  float f;							\ 	  f = u.d;							\ 	  u.d = f;							\ 	}								\       fprintf (FILE, "%.20e", u.d);					\     }									\ 									\   else if ((CODE == 'x')&& (GET_CODE(X) == CONST_INT))			\     fprintf(FILE,"0x%x", 0xffff& (INTVAL(X)));				\ 									\   else if ((CODE == 'd')&& (GET_CODE(X) == CONST_INT))			\     fprintf(FILE,"%d", (INTVAL(X)));					\ 									\   else if ((CODE) == 'd')						\     fatal ("Code d was found& insn was not CONST_INT");		\ 									\   else									\     output_addr_const (FILE, X);					\ }
end_define

begin_comment
comment|/* Print a memory operand whose address is X, on file FILE.  */
end_comment

begin_define
define|#
directive|define
name|PRINT_OPERAND_ADDRESS
parameter_list|(
name|FILE
parameter_list|,
name|ADDR
parameter_list|)
define|\
value|{									\   register rtx addr	 = ADDR;					\   register char **reg_ptr = (TARGET_NAME_REGS) ? reg_names : reg_numchar; \ 									\   switch (GET_CODE (addr))						\     {									\     default:								\       abort_with_insn (addr, "PRINT_OPERAND_ADDRESS, illegal insn #1");	\       break;								\ 									\     case REG:								\       fprintf (FILE, "0(%s)", reg_ptr [REGNO (addr)]);			\       break;								\ 									\     case PLUS:								\       {									\ 	register rtx reg    = (rtx)0;					\ 	register rtx offset = (rtx)0;					\ 	register rtx arg0   = XEXP (addr, 0);				\ 	register rtx arg1   = XEXP (addr, 1);				\ 									\ 	if (GET_CODE (arg0) == REG)					\ 	  {								\ 	    reg = arg0;							\ 	    offset = arg1;						\ 	    if (GET_CODE (offset) == REG)				\ 	      abort_with_insn (addr, "PRINT_OPERAND_ADDRESS, 2 regs");	\ 	  }								\ 	else if (GET_CODE (arg1) == REG)				\ 	  {								\ 	    reg = arg1;							\ 	    offset = arg0;						\ 	  }								\ 	else if (CONSTANT_P (arg0)&& CONSTANT_P (arg1))		\ 	  {								\ 	    output_addr_const (FILE, addr);				\ 	    break;							\ 	  }								\ 	else								\ 	  abort_with_insn (addr, "PRINT_OPERAND_ADDRESS, no regs");	\ 									\ 	if (!CONSTANT_P (offset))					\ 	  abort_with_insn (addr, "PRINT_OPERAND_ADDRESS, illegal insn #2"); \ 									\ 	output_addr_const (FILE, offset);				\ 	fprintf (FILE, "(%s)", reg_ptr [REGNO (reg)]);			\       }									\       break;								\ 									\     case LABEL_REF:							\     case SYMBOL_REF:							\     case CONST_INT:							\     case CONST:								\       output_addr_const (FILE, addr);					\       break;								\     }									\ }
end_define

begin_comment
comment|/* How to tell the debugger about changes of source files.  Note, the    mips ECOFF format cannot deal with changes of files inside of    functions, which means the output of parser generators like bison    is generally not debuggable without using the -l switch.  Lose,    lose, lose.  Silicon graphics seems to want all .file's hardwired    to 1.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SET_FILE_NUMBER
end_ifndef

begin_define
define|#
directive|define
name|SET_FILE_NUMBER
parameter_list|()
value|++num_source_filenames
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ASM_OUTPUT_SOURCE_FILENAME
parameter_list|(
name|STREAM
parameter_list|,
name|NAME
parameter_list|)
define|\
value|{									\   SET_FILE_NUMBER ();							\   fprintf (STREAM, "\t%s.file\t%d \"%s\"\n",				\ 	   (TARGET_GAS || !inside_function) ? "" : "#",			\ 	   num_source_filenames, NAME);					\ }
end_define

begin_comment
comment|/* This is how to output a note the debugger telling it the line number    to which the following sequence of instructions corresponds.    Silicon graphics puts a label after each .loc.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LABEL_AFTER_LOC
end_ifndef

begin_define
define|#
directive|define
name|LABEL_AFTER_LOC
parameter_list|(
name|STREAM
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ASM_OUTPUT_SOURCE_LINE
parameter_list|(
name|STREAM
parameter_list|,
name|LINE
parameter_list|)
define|\
value|{									\   fprintf (STREAM, "\n\t.loc\t%d %d\n", num_source_filenames, LINE);	\   LABEL_AFTER_LOC (STREAM);						\ }
end_define

begin_comment
comment|/* The MIPS implementation uses some labels for it's own purposed.  The    following lists what labels are created, and are all formed by the    pattern $L[a-z].*.  The machine independent portion of GCC creates    labels matching:  $L[A-Z][0-9]+ and $L[0-9]+.  	LM[0-9]+	Sillicon graphics label before each stmt. 	$Lb[0-9]+	Begin blocks for MIPS debug support 	$Ldtable	Beginning of the PIC data table 	$Le[0-9]+	End blocks for MIPS debug support 	$Ls[0-9]+	FP-SP difference if -fomit-frame-pointer  */
end_comment

begin_comment
comment|/* This is how to output the definition of a user-level label named NAME,    such as the label on a static function or variable NAME.     If we are optimizing the gp, remember that this label has been put    out, so we know not to emit an .extern for it in mips_asm_file_end.    We use one of the common bits in the IDENTIFIER tree node for this,    since those bits seem to be unused, and we don't have any method    of getting the decl nodes from the name.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|COLLECT
end_ifndef

begin_define
define|#
directive|define
name|ASM_OUTPUT_LABEL
parameter_list|(
name|STREAM
parameter_list|,
name|NAME
parameter_list|)
define|\
value|do {									\   assemble_name (STREAM, NAME);						\   fputs (":\n", STREAM);						\ 									\   if (TARGET_GP_OPT&& mips_section_threshold != 0)			\     {									\       tree name_tree = get_identifier (NAME);				\       TREE_ADDRESSABLE (name_tree) = 1;					\     }									\ } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ASM_OUTPUT_LABEL
parameter_list|(
name|STREAM
parameter_list|,
name|NAME
parameter_list|)
define|\
value|do {									\   assemble_name (STREAM, NAME);						\   fputs (":\n", STREAM);						\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This is how to output a command to make the user-level label named NAME    defined for reference from other files.  */
end_comment

begin_define
define|#
directive|define
name|ASM_GLOBALIZE_LABEL
parameter_list|(
name|STREAM
parameter_list|,
name|NAME
parameter_list|)
define|\
value|do {									\     fputs ("\t.globl\t", STREAM);					\     assemble_name (STREAM, NAME);					\     fputs ("\n", STREAM);						\   } while (0)
end_define

begin_comment
comment|/* This says how to output an assembler line    to define a global common symbol.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_COMMON
parameter_list|(
name|STREAM
parameter_list|,
name|NAME
parameter_list|,
name|SIZE
parameter_list|,
name|ROUNDED
parameter_list|)
define|\
value|do {									\   fputs ("\n\t.comm\t", (STREAM));					\   assemble_name ((STREAM), (NAME));					\   fprintf ((STREAM), ",%u\n", (ROUNDED));				\ 									\   if (TARGET_GP_OPT&& mips_section_threshold != 0)			\     {									\       tree name_tree = get_identifier (NAME);				\       TREE_ADDRESSABLE (name_tree) = 1;					\     }									\ } while (0)
end_define

begin_comment
comment|/* This says how to output an assembler line    to define a local common symbol.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_LOCAL
parameter_list|(
name|STREAM
parameter_list|,
name|NAME
parameter_list|,
name|SIZE
parameter_list|,
name|ROUNDED
parameter_list|)
define|\
value|do {									\   fputs ("\n\t.lcomm\t", (STREAM));					\   assemble_name ((STREAM), (NAME));					\   fprintf ((STREAM), ",%u\n", (ROUNDED));				\ 									\   if (TARGET_GP_OPT&& mips_section_threshold != 0)			\     {									\       tree name_tree = get_identifier (NAME);				\       TREE_ADDRESSABLE (name_tree) = 1;					\     }									\ } while (0)
end_define

begin_comment
comment|/* This says how to output an external.  It would be possible not to    output anything and let undefined symbol become external. However    the assembler uses length information on externals to allocate in    data/sdata bss/sbss, thereby saving exec time.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_EXTERNAL
parameter_list|(
name|STREAM
parameter_list|,
name|DECL
parameter_list|,
name|NAME
parameter_list|)
define|\
value|mips_output_external(STREAM,DECL,NAME)
end_define

begin_comment
comment|/* This says what to print at the end of the assembly file */
end_comment

begin_define
define|#
directive|define
name|ASM_FILE_END
parameter_list|(
name|STREAM
parameter_list|)
value|mips_asm_file_end(STREAM)
end_define

begin_comment
comment|/* This is how to declare a function name.  The actual work of    emitting the label is moved to function_prologue, so that we can    get the line number correctly emitted before the .ent directive,    and after any .file directives.     Also, switch files if we are optimizing the global pointer.  */
end_comment

begin_define
define|#
directive|define
name|ASM_DECLARE_FUNCTION_NAME
parameter_list|(
name|STREAM
parameter_list|,
name|NAME
parameter_list|,
name|DECL
parameter_list|)
define|\
value|{									\   extern FILE *asm_out_text_file;					\   if (TARGET_GP_OPT)							\     STREAM = asm_out_text_file;						\ 									\   current_function_name = NAME;						\ }
end_define

begin_comment
comment|/* This is how to output a reference to a user-level label named NAME.    `assemble_name' uses this.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_LABELREF
parameter_list|(
name|STREAM
parameter_list|,
name|NAME
parameter_list|)
define|\
value|fprintf (STREAM, "%s", NAME)
end_define

begin_comment
comment|/* This is how to output an internal numbered label where    PREFIX is the class of label and NUM is the number within the class.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_INTERNAL_LABEL
parameter_list|(
name|STREAM
parameter_list|,
name|PREFIX
parameter_list|,
name|NUM
parameter_list|)
define|\
value|fprintf (STREAM, "$%s%d:\n", PREFIX, NUM)
end_define

begin_comment
comment|/* This is how to store into the string LABEL    the symbol_ref name of an internal numbered label where    PREFIX is the class of label and NUM is the number within the class.    This is suitable for output with `assemble_name'.  */
end_comment

begin_define
define|#
directive|define
name|ASM_GENERATE_INTERNAL_LABEL
parameter_list|(
name|LABEL
parameter_list|,
name|PREFIX
parameter_list|,
name|NUM
parameter_list|)
define|\
value|sprintf (LABEL, "*$%s%d", PREFIX, NUM)
end_define

begin_comment
comment|/* This is how to output an assembler line defining a `double' constant.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_DOUBLE
parameter_list|(
name|STREAM
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|{									\   union { double d; long l[2]; } u2;					\   u2.d = VALUE;								\   fprintf (STREAM, "\t.word\t0x%08lx\t\t# %.20g\n\t.word\t0x%08lx\n",	\ 	   u2.l[0], u2.d, u2.l[1]);					\ }
end_define

begin_comment
comment|/* This is how to output an assembler line defining a `float' constant.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_FLOAT
parameter_list|(
name|STREAM
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|{									\   union { float f; long l; } u2;					\   u2.f = VALUE;								\   fprintf (STREAM, "\t.word\t0x%08lx\t\t# %.12g\n", u2.l, u2.f);	\ }
end_define

begin_comment
comment|/* This is how to output an assembler line defining an `int' constant.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_INT
parameter_list|(
name|STREAM
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|{									\   fprintf (STREAM, "\t.word\t");					\   output_addr_const (STREAM, (VALUE));					\   fprintf (STREAM, "\n");						\ }
end_define

begin_comment
comment|/* Likewise for `char' and `short' constants.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_SHORT
parameter_list|(
name|STREAM
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|{									\   fprintf (STREAM, "\t.half\t");					\   output_addr_const (STREAM, (VALUE));					\   fprintf (STREAM, "\n");						\ }
end_define

begin_define
define|#
directive|define
name|ASM_OUTPUT_CHAR
parameter_list|(
name|STREAM
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|{									\   fprintf (STREAM, "\t.byte\t");					\   output_addr_const (STREAM, (VALUE));					\   fprintf (STREAM, "\n");						\ }
end_define

begin_comment
comment|/* This is how to output an assembler line defining an `int' constant,    which is not in tree format (for collect.c).  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_INT_CONST
parameter_list|(
name|STREAM
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|fprintf(STREAM, "\t.word\t%d\n", VALUE)
end_define

begin_comment
comment|/* This is how to output an assembler line defining an external/static    address which is not in tree format (for collect.c).  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_PTR_INT_SUM
parameter_list|(
name|STREAM
parameter_list|,
name|NAME
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|do {									\   fprintf (STREAM, "\t.word\t");					\   ASM_OUTPUT_LABELREF (STREAM, NAME);					\   fprintf (STREAM, "+%d\n", VALUE);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|ASM_OUTPUT_LABELREF_AS_INT
parameter_list|(
name|STREAM
parameter_list|,
name|NAME
parameter_list|)
define|\
value|do {									\   fprintf (STREAM, "\t.word\t");					\   ASM_OUTPUT_LABELREF (STREAM, NAME);					\   fprintf (STREAM, "\n");						\ } while (0)
end_define

begin_comment
comment|/* This is how to output an assembler line for a numeric constant byte.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_BYTE
parameter_list|(
name|STREAM
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|{									\   fprintf (STREAM, "\t.byte\t0x%x\n", (VALUE));				\ }
end_define

begin_comment
comment|/* This is how to output an element of a case-vector that is absolute.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_ADDR_VEC_ELT
parameter_list|(
name|STREAM
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|{									\   fprintf (STREAM, "\t.word\t$L%d\n", VALUE);				\ }
end_define

begin_comment
comment|/* This is how to output an element of a case-vector that is relative.    (We  do not use such vectors,    but we must define this macro anyway.)  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_ADDR_DIFF_ELT
parameter_list|(
name|STREAM
parameter_list|,
name|VALUE
parameter_list|,
name|REL
parameter_list|)
define|\
value|{									\   fprintf (STREAM, "\t.word\t$L%d-$L%d\n", VALUE, REL);			\ }
end_define

begin_comment
comment|/* This is how to emit the initial label for switch statements.  We    need to put the switch labels somewhere else from the text section,    because the MIPS assembler gets real confused about line numbers if    .word's appear in the text section.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_CASE_LABEL
parameter_list|(
name|STREAM
parameter_list|,
name|PREFIX
parameter_list|,
name|NUM
parameter_list|,
name|JUMPTABLE
parameter_list|)
define|\
value|{									\   rdata_section ();							\   ASM_OUTPUT_ALIGN (STREAM, 2);						\   ASM_OUTPUT_INTERNAL_LABEL (STREAM, PREFIX, NUM);			\ }
end_define

begin_comment
comment|/* Output at the end of a switch's jump table.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_CASE_END
parameter_list|(
name|STREAM
parameter_list|,
name|NUM
parameter_list|,
name|INSN
parameter_list|)
define|\
value|{									\   text_section ();							\ }
end_define

begin_comment
comment|/* This is how to output an assembler line    that says to advance the location counter    to a multiple of 2**LOG bytes.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_ALIGN
parameter_list|(
name|STREAM
parameter_list|,
name|LOG
parameter_list|)
define|\
value|{									\   int mask = (1<< (LOG)) - 1;						\   fprintf (STREAM, "\t.align\t%d\n", (LOG));				\ }
end_define

begin_comment
comment|/* This is how to output an assembler line to to advance the location    counter by SIZE bytes.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_SKIP
parameter_list|(
name|STREAM
parameter_list|,
name|SIZE
parameter_list|)
define|\
value|{									\   fprintf (STREAM, "\t.space\t%u\n", (SIZE));				\ }
end_define

begin_comment
comment|/* This is how to output a string.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_ASCII
parameter_list|(
name|STREAM
parameter_list|,
name|STRING
parameter_list|,
name|LEN
parameter_list|)
define|\
value|do {									\   register int i, c, len = LEN, cur_pos = 17;				\   register unsigned char *string = (unsigned char *)STRING;		\   fprintf (STREAM, "\t.ascii\t\"");					\   for (i = 0; i< len; i++)						\     {									\       register int c = string[i];					\ 									\       switch (c)							\ 	{								\ 	case '\"':							\ 	case '\\':							\ 	  putc ('\\', STREAM);						\ 	  putc (c, STREAM);						\ 	  cur_pos += 2;							\ 	  break;							\ 									\ 	case TARGET_NEWLINE:						\ 	  fputs ("\\n", STREAM);					\ 	  if (i+1< len							\&& (((c = string[i+1])>= '\040'&& c<= '~')		\ 		  || c == TARGET_TAB))					\ 	    cur_pos = 32767;
comment|/* break right here */
value|\ 	  else								\ 	    cur_pos += 2;						\ 	  break;							\ 									\ 	case TARGET_TAB:						\ 	  fputs ("\\t", STREAM);					\ 	  cur_pos += 2;							\ 	  break;							\ 									\ 	case TARGET_FF:							\ 	  fputs ("\\f", STREAM);					\ 	  cur_pos += 2;							\ 	  break;							\ 									\ 	case TARGET_BS:							\ 	  fputs ("\\b", STREAM);					\ 	  cur_pos += 2;							\ 	  break;							\ 									\ 	case TARGET_CR:							\ 	  fputs ("\\r", STREAM);					\ 	  cur_pos += 2;							\ 	  break;							\ 									\ 	  default:							\ 	  if (c>= ' '&& c< 0177)					\ 	    {								\ 	      putc (c, STREAM);						\ 	      cur_pos++;						\ 	    }								\ 	  else								\ 	    {								\ 	      fprintf (STREAM, "\\%03o", c);				\ 	      cur_pos += 4;						\ 	    }								\ 	}								\ 									\       if (cur_pos> 72&& i+1< len)					\ 	{								\ 	  cur_pos = 17;							\ 	  fprintf (STREAM, "\"\n\t.ascii\t\"");				\ 	}								\     }									\   fprintf (STREAM, "\"\n");						\ } while (0)
end_define

begin_comment
comment|/* Handle certain cpp directives used in header files on sysV.  */
end_comment

begin_define
define|#
directive|define
name|SCCS_DIRECTIVE
end_define

begin_comment
comment|/* Output #ident as a in the read-only data section.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_IDENT
parameter_list|(
name|FILE
parameter_list|,
name|STRING
parameter_list|)
define|\
value|{									\   char *p = STRING;							\   int size = strlen (p) + 1;						\   rdata_section ();							\   assemble_string (p, size);						\ }
end_define

begin_escape
end_escape

begin_comment
comment|/* Output before read-only data.  */
end_comment

begin_define
define|#
directive|define
name|TEXT_SECTION_ASM_OP
value|"\t.text"
end_define

begin_comment
comment|/* Output before writable data.  */
end_comment

begin_define
define|#
directive|define
name|DATA_SECTION_ASM_OP
value|"\t.data"
end_define

begin_comment
comment|/* Output before writable  short data.  */
end_comment

begin_define
define|#
directive|define
name|SDATA_SECTION_ASM_OP
value|"\t.sdata"
end_define

begin_comment
comment|/* Output before read-only data.  */
end_comment

begin_define
define|#
directive|define
name|RDATA_SECTION_ASM_OP
value|"\t.rdata"
end_define

begin_comment
comment|/* What other sections we support other than the normal .data/.text.  */
end_comment

begin_define
define|#
directive|define
name|EXTRA_SECTIONS
value|in_sdata, in_rdata, in_last_p1
end_define

begin_comment
comment|/* Define the additional functions to select our additional sections.  */
end_comment

begin_comment
comment|/* on the MIPS it is not a good idea to put constants in the text    section, since this defeats the sdata/data mechanism. This is    especially true when -O is used. In this case an effort is made to    address with faster (gp) register relative addressing, which can    only get at sdata and sbss items (there is no stext !!)  However,    if the constant is too large for sdata, and it's readonly, it    will go into the .rdata section. */
end_comment

begin_define
define|#
directive|define
name|EXTRA_SECTION_FUNCTIONS
define|\
value|void									\ sdata_section ()							\ {									\   if (in_section != in_sdata)						\     {									\       fprintf (asm_out_file, "%s\n", SDATA_SECTION_ASM_OP);		\       in_section = in_sdata;						\     }									\ }									\ 									\ void									\ rdata_section ()							\ {									\   if (in_section != in_rdata)						\     {									\       fprintf (asm_out_file, "%s\n", RDATA_SECTION_ASM_OP);		\       in_section = in_rdata;						\     }									\ }
end_define

begin_comment
comment|/* Given a decl node or constant node, choose the section to output it in    and select that section.  */
end_comment

begin_define
define|#
directive|define
name|SELECT_SECTION_MODE
parameter_list|(
name|MODE
parameter_list|,
name|RTX
parameter_list|)
define|\
value|{									\   extern int mips_section_threshold;					\   if ((GET_MODE_SIZE(MODE) / BITS_PER_UNIT)<= mips_section_threshold	\&& mips_section_threshold> 0)					\     sdata_section ();							\   else									\     rdata_section ();							\ }									\  #define SELECT_SECTION(DECL)						\ {									\   extern int mips_section_threshold;					\   if (int_size_in_bytes (TREE_TYPE (DECL))<= mips_section_threshold	\&& mips_section_threshold> 0)					\     sdata_section ();							\   else if (TREE_CODE (DECL) == STRING_CST)				\     {									\       if (flag_writable_strings)					\ 	data_section ();						\       else								\ 	rdata_section ();						\     }									\   else if (TREE_CODE (DECL) != VAR_DECL)				\     rdata_section ();							\   else if (!TREE_READONLY (DECL) || TREE_VOLATILE (DECL))		\     data_section ();							\   else									\     rdata_section ();							\ }
end_define

begin_escape
end_escape

begin_comment
comment|/* Store in OUTPUT a string (made with alloca) containing    an assembler-name for a local static variable named NAME.    LABELNO is an integer which is different for each call.  */
end_comment

begin_define
define|#
directive|define
name|ASM_FORMAT_PRIVATE_NAME
parameter_list|(
name|OUTPUT
parameter_list|,
name|NAME
parameter_list|,
name|LABELNO
parameter_list|)
define|\
value|( (OUTPUT) = (char *) alloca (strlen ((NAME)) + 10),			\   sprintf ((OUTPUT), "%s.%d", (NAME), (LABELNO)))
end_define

begin_define
define|#
directive|define
name|ASM_OUTPUT_REG_POP
parameter_list|(
name|STREAM
parameter_list|,
name|REGNO
parameter_list|)
define|\
value|do {									\   extern char *reg_numchar[];						\   char **reg_name_ptr = (TARGET_NAME_REGS) ? reg_names : reg_numchar;	\   fprintf (STREAM, "\tsubu\t%s,%s,4\n\tsw\t%s,0(%s)\n",			\ 	   reg_name_ptr[STACK_POINTER_REGNUM],				\ 	   reg_name_ptr[STACK_POINTER_REGNUM],				\ 	   reg_name_ptr[REGNO],						\ 	   reg_name_ptr[STACK_POINTER_REGNUM]);				\ } while (0)
end_define

begin_define
define|#
directive|define
name|ASM_OUTPUT_REG_PUSH
parameter_list|(
name|STREAM
parameter_list|,
name|REGNO
parameter_list|)
define|\
value|do {									\   extern char *reg_numchar[];						\   char **reg_name_ptr = (TARGET_NAME_REGS) ? reg_names : reg_numchar;	\   fprintf (STREAM, "\tlw\t%s,0(%s)\n\taddu\t%s,%s,4\n",			\ 	   reg_name_ptr[REGNO],						\ 	   reg_name_ptr[STACK_POINTER_REGNUM],				\ 	   reg_name_ptr[STACK_POINTER_REGNUM],				\ 	   reg_name_ptr[STACK_POINTER_REGNUM]);				\ } while (0)
end_define

begin_comment
comment|/* Define the parentheses used to group arithmetic operations    in assembler code.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OPEN_PAREN
value|"("
end_define

begin_define
define|#
directive|define
name|ASM_CLOSE_PAREN
value|")"
end_define

begin_escape
end_escape

begin_comment
comment|/* Tell G++'s collect that MIPS' based ports do not have leading    underscores.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_UNDERSCORES
end_ifndef

begin_define
define|#
directive|define
name|NO_UNDERSCORES
end_define

begin_endif
endif|#
directive|endif
endif|NO_UNDERSCORES
end_endif

begin_comment
comment|/* Tell G++ that we need to run collect.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|USE_COLLECT
end_ifndef

begin_define
define|#
directive|define
name|USE_COLLECT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EXTENDED_COFF
end_ifndef

begin_define
define|#
directive|define
name|EXTENDED_COFF
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The following are for collect.c which has it's own idea of    which macros should be used.  */
end_comment

begin_define
define|#
directive|define
name|ASM_INT_OP
value|".word "
end_define

begin_define
define|#
directive|define
name|ASM_SHORT_OP
value|".half "
end_define

begin_define
define|#
directive|define
name|ASM_CHAR_OP
value|".byte "
end_define

end_unit

