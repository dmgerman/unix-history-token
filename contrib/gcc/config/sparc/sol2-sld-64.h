begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler, for 64-bit SPARC    running Solaris 2 using the system linker.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|AS_SPARC64_FLAG
end_ifdef

begin_include
include|#
directive|include
file|"sparc/sparc_bi.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"sparc/sparc.h"
end_include

begin_include
include|#
directive|include
file|"dbxelf.h"
end_include

begin_include
include|#
directive|include
file|"elfos.h"
end_include

begin_include
include|#
directive|include
file|"svr4.h"
end_include

begin_include
include|#
directive|include
file|"sparc/sysv4.h"
end_include

begin_include
include|#
directive|include
file|"sparc/sol2.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|AS_SPARC64_FLAG
end_ifdef

begin_comment
comment|/* At least up through Solaris 2.6,    the system linker does not work with DWARF or DWARF2,    since it does not have working support for relocations    to unaligned data.  */
end_comment

begin_define
define|#
directive|define
name|LINKER_DOES_NOT_WORK_WITH_DWARF2
end_define

begin_comment
comment|/* A 64 bit v9 compiler with stack-bias */
end_comment

begin_if
if|#
directive|if
name|TARGET_CPU_DEFAULT
operator|==
name|TARGET_CPU_v9
operator|||
name|TARGET_CPU_DEFAULT
operator|==
name|TARGET_CPU_ultrasparc
end_if

begin_undef
undef|#
directive|undef
name|TARGET_DEFAULT
end_undef

begin_define
define|#
directive|define
name|TARGET_DEFAULT
define|\
value|(MASK_V9 + MASK_PTR64 + MASK_64BIT
comment|/* + MASK_HARD_QUAD */
value|+ \    MASK_STACK_BIAS + MASK_EPILOGUE + MASK_FPU + MASK_LONG_DOUBLE_128)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The default code model.  */
end_comment

begin_undef
undef|#
directive|undef
name|SPARC_DEFAULT_CMODEL
end_undef

begin_define
define|#
directive|define
name|SPARC_DEFAULT_CMODEL
value|CM_MEDANY
end_define

begin_undef
undef|#
directive|undef
name|LONG_DOUBLE_TYPE_SIZE
end_undef

begin_define
define|#
directive|define
name|LONG_DOUBLE_TYPE_SIZE
value|128
end_define

begin_undef
undef|#
directive|undef
name|ASM_CPU32_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|ASM_CPU32_DEFAULT_SPEC
value|""
end_define

begin_undef
undef|#
directive|undef
name|ASM_CPU64_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|ASM_CPU64_DEFAULT_SPEC
value|AS_SPARC64_FLAG
end_define

begin_if
if|#
directive|if
name|TARGET_CPU_DEFAULT
operator|==
name|TARGET_CPU_v9
end_if

begin_undef
undef|#
directive|undef
name|CPP_CPU64_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_CPU64_DEFAULT_SPEC
value|""
end_define

begin_undef
undef|#
directive|undef
name|ASM_CPU32_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|ASM_CPU32_DEFAULT_SPEC
value|"-xarch=v8plus"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|TARGET_CPU_DEFAULT
operator|==
name|TARGET_CPU_ultrasparc
end_if

begin_undef
undef|#
directive|undef
name|CPP_CPU64_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_CPU64_DEFAULT_SPEC
value|""
end_define

begin_undef
undef|#
directive|undef
name|ASM_CPU32_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|ASM_CPU32_DEFAULT_SPEC
value|"-xarch=v8plusa"
end_define

begin_undef
undef|#
directive|undef
name|ASM_CPU64_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|ASM_CPU64_DEFAULT_SPEC
value|AS_SPARC64_FLAG "a"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The sun bundled assembler doesn't accept -Yd, (and neither does gas).    It's safe to pass -s always, even if -g is not used.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_SPEC
end_undef

begin_define
define|#
directive|define
name|ASM_SPEC
value|"\ %{v:-V} %{Qy:} %{!Qn:-Qy} %{n} %{T} %{Ym,*} %{Wa,*:%*} -s \ %{fpic:-K PIC} %{fPIC:-K PIC} \ %(asm_cpu)\ "
end_define

begin_if
if|#
directive|if
name|DEFAULT_ARCH32_P
end_if

begin_define
define|#
directive|define
name|DEF_ARCH32_SPEC
parameter_list|(
name|__str
parameter_list|)
value|"%{!m64:" __str "}"
end_define

begin_define
define|#
directive|define
name|DEF_ARCH64_SPEC
parameter_list|(
name|__str
parameter_list|)
value|"%{m64:" __str "}"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DEF_ARCH32_SPEC
parameter_list|(
name|__str
parameter_list|)
value|"%{m32:" __str "}"
end_define

begin_define
define|#
directive|define
name|DEF_ARCH64_SPEC
parameter_list|(
name|__str
parameter_list|)
value|"%{!m32:" __str "}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|CPP_CPU_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_CPU_SPEC
value|"\ %{mcypress:} \ %{msparclite:-D__sparclite__} \ %{mf930:-D__sparclite__} %{mf934:-D__sparclite__} \ %{mv8:" DEF_ARCH32_SPEC("-D__sparcv8") "} \ %{msupersparc:-D__supersparc__ " DEF_ARCH32_SPEC("-D__sparcv8") "} \ %{mcpu=sparclet:-D__sparclet__} %{mcpu=tsc701:-D__sparclet__} \ %{mcpu=sparclite:-D__sparclite__} \ %{mcpu=f930:-D__sparclite__} %{mcpu=f934:-D__sparclite__} \ %{mcpu=v8:" DEF_ARCH32_SPEC("-D__sparcv8") "} \ %{mcpu=supersparc:-D__supersparc__ " DEF_ARCH32_SPEC("-D__sparcv8") "} \ %{mcpu=v9:" DEF_ARCH32_SPEC("-D__sparcv8") "} \ %{mcpu=ultrasparc:" DEF_ARCH32_SPEC("-D__sparcv8") "} \ %{!mcpu*:%{!mcypress:%{!msparclite:%{!mf930:%{!mf934:%{!mv8:%{!msupersparc:%(cpp_cpu_default)}}}}}}} \ "
end_define

begin_undef
undef|#
directive|undef
name|ASM_CPU_SPEC
end_undef

begin_define
define|#
directive|define
name|ASM_CPU_SPEC
value|"\ %{mcpu=ultrasparc:" DEF_ARCH32_SPEC("-xarch=v8plusa") DEF_ARCH64_SPEC(AS_SPARC64_FLAG "a") "} \ %{mcpu=v9:" DEF_ARCH32_SPEC("-xarch=v8plus") DEF_ARCH64_SPEC(AS_SPARC64_FLAG) "} \ %{!mcpu=ultrasparc:%{!mcpu=v9:%{mcpu*:" DEF_ARCH32_SPEC("-xarch=v8") DEF_ARCH64_SPEC(AS_SPARC64_FLAG) "}}} \ %{!mcpu*:%(asm_cpu_default)} \ "
end_define

begin_define
define|#
directive|define
name|STARTFILE_SPEC32
value|"\ %{ansi:values-Xc.o%s} \ %{!ansi: \  %{traditional:values-Xt.o%s} \  %{!traditional:values-Xa.o%s}}"
end_define

begin_define
define|#
directive|define
name|STARTFILE_SPEC64
value|"\ %{ansi:/usr/lib/sparcv9/values-Xc.o%s} \ %{!ansi: \  %{traditional:/usr/lib/sparcv9/values-Xt.o%s} \  %{!traditional:/usr/lib/sparcv9/values-Xa.o%s}}"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SPARC_BI_ARCH
end_ifdef

begin_if
if|#
directive|if
name|DEFAULT_ARCH32_P
end_if

begin_define
define|#
directive|define
name|STARTFILE_ARCH_SPEC
value|"\ %{m32:" STARTFILE_SPEC32 "} \ %{m64:" STARTFILE_SPEC64 "} \ %{!m32:%{!m64:" STARTFILE_SPEC32 "}}"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|STARTFILE_ARCH_SPEC
value|"\ %{m32:" STARTFILE_SPEC32 "} \ %{m64:" STARTFILE_SPEC64 "} \ %{!m32:%{!m64:" STARTFILE_SPEC64 "}}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !SPARC_BI_ARCH */
end_comment

begin_comment
comment|/* In this case we define MD_STARTFILE_PREFIX to /usr/lib/sparcv9/ */
end_comment

begin_define
define|#
directive|define
name|STARTFILE_ARCH_SPEC
value|STARTFILE_SPEC32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !SPARC_BI_ARCH */
end_comment

begin_undef
undef|#
directive|undef
name|STARTFILE_SPEC
end_undef

begin_define
define|#
directive|define
name|STARTFILE_SPEC
value|"%{!shared: \ 			 %{!symbolic: \ 			  %{p:mcrt1.o%s} \                           %{!p: \ 	                    %{pg:gcrt1.o%s gmon.o%s} \                             %{!pg:crt1.o%s}}}} \ 			crti.o%s " STARTFILE_ARCH_SPEC " \ 			crtbegin.o%s"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SPARC_BI_ARCH
end_ifdef

begin_undef
undef|#
directive|undef
name|CPP_CPU_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_CPU_DEFAULT_SPEC
define|\
value|(DEFAULT_ARCH32_P ? "\ %{m64:" CPP_CPU64_DEFAULT_SPEC "} \ %{!m64:" CPP_CPU32_DEFAULT_SPEC "} \ " : "\ %{m32:" CPP_CPU32_DEFAULT_SPEC "} \ %{!m32:" CPP_CPU64_DEFAULT_SPEC "} \ ")
end_define

begin_undef
undef|#
directive|undef
name|ASM_CPU_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|ASM_CPU_DEFAULT_SPEC
define|\
value|(DEFAULT_ARCH32_P ? "\ %{m64:" ASM_CPU64_DEFAULT_SPEC "} \ %{!m64:" ASM_CPU32_DEFAULT_SPEC "} \ " : "\ %{m32:" ASM_CPU32_DEFAULT_SPEC "} \ %{!m32:" ASM_CPU64_DEFAULT_SPEC "} \ ")
end_define

begin_comment
comment|/* wchar_t is called differently in<wchar.h> for 32 and 64-bit    compilations.  This is called for by SCD 2.4.1, p. 6-83, Figure 6-65    (32-bit) and p. 6P-10, Figure 6.38 (64-bit).  */
end_comment

begin_define
define|#
directive|define
name|NO_BUILTIN_WCHAR_TYPE
end_define

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE
end_undef

begin_define
define|#
directive|define
name|WCHAR_TYPE
value|(TARGET_ARCH64 ? "int" : "long int")
end_define

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE_SIZE
end_undef

begin_define
define|#
directive|define
name|WCHAR_TYPE_SIZE
value|32
end_define

begin_comment
comment|/* Same for wint_t.  See SCD 2.4.1, p. 6-83, Figure 6-66 (32-bit).  There's    no corresponding 64-bit definition, but this is what Solaris 8<iso/wchar_iso.h> uses.  */
end_comment

begin_define
define|#
directive|define
name|NO_BUILTIN_WINT_TYPE
end_define

begin_undef
undef|#
directive|undef
name|WINT_TYPE
end_undef

begin_define
define|#
directive|define
name|WINT_TYPE
value|(TARGET_ARCH64 ? "int" : "long int")
end_define

begin_undef
undef|#
directive|undef
name|WINT_TYPE_SIZE
end_undef

begin_define
define|#
directive|define
name|WINT_TYPE_SIZE
value|32
end_define

begin_undef
undef|#
directive|undef
name|CPP_ARCH32_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_ARCH32_SPEC
value|"-D__SIZE_TYPE__=unsigned\\ int -D__PTRDIFF_TYPE__=int \ -D__WCHAR_TYPE__=long\\ int -D__WINT_TYPE__=long\\ int \ -D__GCC_NEW_VARARGS__ -Acpu=sparc -Amachine=sparc"
end_define

begin_undef
undef|#
directive|undef
name|CPP_ARCH64_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_ARCH64_SPEC
value|"-D__SIZE_TYPE__=long\\ unsigned\\ int -D__PTRDIFF_TYPE__=long\\ int \ -D__WCHAR_TYPE__=int -D__WINT_TYPE__=int \ -D__arch64__ -Acpu=sparc64 -Amachine=sparcv9 -D__sparcv9"
end_define

begin_undef
undef|#
directive|undef
name|CPP_ARCH_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_ARCH_SPEC
value|"\ %{m32:%(cpp_arch32)} \ %{m64:%(cpp_arch64)} \ %{!m32:%{!m64:%(cpp_arch_default)}} \ "
end_define

begin_undef
undef|#
directive|undef
name|ASM_ARCH_SPEC
end_undef

begin_define
define|#
directive|define
name|ASM_ARCH_SPEC
value|""
end_define

begin_undef
undef|#
directive|undef
name|ASM_ARCH32_SPEC
end_undef

begin_define
define|#
directive|define
name|ASM_ARCH32_SPEC
value|""
end_define

begin_undef
undef|#
directive|undef
name|ASM_ARCH64_SPEC
end_undef

begin_define
define|#
directive|define
name|ASM_ARCH64_SPEC
value|""
end_define

begin_undef
undef|#
directive|undef
name|ASM_ARCH_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|ASM_ARCH_DEFAULT_SPEC
value|""
end_define

begin_undef
undef|#
directive|undef
name|SUBTARGET_EXTRA_SPECS
end_undef

begin_define
define|#
directive|define
name|SUBTARGET_EXTRA_SPECS
define|\
value|{ "link_arch32",       LINK_ARCH32_SPEC },              \   { "link_arch64",       LINK_ARCH64_SPEC },              \   { "link_arch_default", LINK_ARCH_DEFAULT_SPEC },	  \   { "link_arch",	 LINK_ARCH_SPEC },
end_define

begin_comment
comment|/* This should be the same as in svr4.h, except with -R added.  */
end_comment

begin_define
define|#
directive|define
name|LINK_ARCH32_SPEC
define|\
value|"%{G:-G} \    %{YP,*} \    %{R*} \    %{compat-bsd: \      %{!YP,*:%{p:-Y P,/usr/ucblib:/usr/ccs/lib/libp:/usr/lib/libp:/usr/ccs/lib:/usr/lib} \        %{pg:-Y P,/usr/ucblib:/usr/ccs/lib/libp:/usr/lib/libp:/usr/ccs/lib:/usr/lib} \        %{!p:%{!pg:-Y P,/usr/ucblib:/usr/ccs/lib:/usr/lib}}} \      -R /usr/ucblib} \    %{!compat-bsd: \      %{!YP,*:%{p:-Y P,/usr/ccs/lib/libp:/usr/lib/libp:/usr/ccs/lib:/usr/lib} \        %{pg:-Y P,/usr/ccs/lib/libp:/usr/lib/libp:/usr/ccs/lib:/usr/lib} \        %{!p:%{!pg:-Y P,/usr/ccs/lib:/usr/lib}}}}"
end_define

begin_define
define|#
directive|define
name|LINK_ARCH64_SPEC
define|\
value|"%{mcmodel=medlow:-M /usr/lib/ld/sparcv9/map.below4G} \    %{G:-G} \    %{YP,*} \    %{R*} \    %{compat-bsd: \      %{!YP,*:%{p:-Y P,/usr/ucblib/sparcv9:/usr/lib/libp/sparcv9:/usr/lib/sparcv9} \        %{pg:-Y P,/usr/ucblib/sparcv9:/usr/lib/libp/sparcv9:/usr/lib/sparcv9} \        %{!p:%{!pg:-Y P,/usr/ucblib/sparcv9:/usr/lib/sparcv9}}} \      -R /usr/ucblib} \    %{!compat-bsd: \      %{!YP,*:%{p:-Y P,/usr/lib/libp/sparcv9:/usr/lib/sparcv9} \        %{pg:-Y P,/usr/lib/libp/sparcv9:/usr/lib/sparcv9} \        %{!p:%{!pg:-Y P,/usr/lib/sparcv9}}}}"
end_define

begin_define
define|#
directive|define
name|LINK_ARCH_SPEC
value|"\ %{m32:%(link_arch32)} \ %{m64:%(link_arch64)} \ %{!m32:%{!m64:%(link_arch_default)}} \ "
end_define

begin_define
define|#
directive|define
name|LINK_ARCH_DEFAULT_SPEC
define|\
value|(DEFAULT_ARCH32_P ? LINK_ARCH32_SPEC : LINK_ARCH64_SPEC)
end_define

begin_undef
undef|#
directive|undef
name|LINK_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_SPEC
define|\
value|"%{h*} %{v:-V} \    %{b} %{Wl,*:%*} \    %{static:-dn -Bstatic} \    %{shared:-G -dy %{!mimpure-text:-z text}} \    %{symbolic:-Bsymbolic -G -dy -z text} \    %(link_arch) \    %{Qy:} %{!Qn:-Qy}"
end_define

begin_undef
undef|#
directive|undef
name|CC1_SPEC
end_undef

begin_if
if|#
directive|if
name|DEFAULT_ARCH32_P
end_if

begin_define
define|#
directive|define
name|CC1_SPEC
value|"\ %{sun4:} %{target:} \ %{mcypress:-mcpu=cypress} \ %{msparclite:-mcpu=sparclite} %{mf930:-mcpu=f930} %{mf934:-mcpu=f934} \ %{mv8:-mcpu=v8} %{msupersparc:-mcpu=supersparc} \ %{m64:-mptr64 -mstack-bias -mno-v8plus \   %{!mcpu*:%{!mcypress:%{!msparclite:%{!mf930:%{!mf934:%{!mv8*:%{!msupersparc:-mcpu=v9}}}}}}}} \ "
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CC1_SPEC
value|"\ %{sun4:} %{target:} \ %{mcypress:-mcpu=cypress} \ %{msparclite:-mcpu=sparclite} %{mf930:-mcpu=f930} %{mf934:-mcpu=f934} \ %{mv8:-mcpu=v8} %{msupersparc:-mcpu=supersparc} \ %{m32:-mptr32 -mno-stack-bias \   %{!mcpu*:%{!mcypress:%{!msparclite:%{!mf930:%{!mf934:%{!mv8*:%{!msupersparc:-mcpu=cypress}}}}}}}} \ %{mv8plus:-m32 -mptr32 -mno-stack-bias \   %{!mcpu*:%{!mcypress:%{!msparclite:%{!mf930:%{!mf934:%{!mv8:%{!msupersparc:-mcpu=v9}}}}}}}} \ "
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|DEFAULT_ARCH32_P
end_if

begin_define
define|#
directive|define
name|MULTILIB_DEFAULTS
value|{ "m32" }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MULTILIB_DEFAULTS
value|{ "m64" }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !SPARC_BI_ARCH */
end_comment

begin_comment
comment|/*  * This should be the same as in sol2-sld.h, except with "/sparcv9"  * appended to the paths and /usr/ccs/lib is no longer necessary  */
end_comment

begin_undef
undef|#
directive|undef
name|LINK_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_SPEC
define|\
value|"%{h*} %{v:-V} \    %{b} %{Wl,*:%*} \    %{static:-dn -Bstatic} \    %{shared:-G -dy %{!mimpure-text:-z text}} \    %{symbolic:-Bsymbolic -G -dy -z text} \    %{mcmodel=medlow:-M /usr/lib/ld/sparcv9/map.below4G} \    %{G:-G} \    %{YP,*} \    %{R*} \    %{compat-bsd: \      %{!YP,*:%{p:-Y P,/usr/ucblib/sparcv9:/usr/lib/libp/sparcv9:/usr/lib/sparcv9} \        %{pg:-Y P,/usr/ucblib/sparcv9:/usr/lib/libp/sparcv9:/usr/lib/sparcv9} \        %{!p:%{!pg:-Y P,/usr/ucblib/sparcv9:/usr/lib/sparcv9}}} \      -R /usr/ucblib} \    %{!compat-bsd: \      %{!YP,*:%{p:-Y P,/usr/lib/libp/sparcv9:/usr/lib/sparcv9} \        %{pg:-Y P,/usr/lib/libp/sparcv9:/usr/lib/sparcv9} \        %{!p:%{!pg:-Y P,/usr/lib/sparcv9}}}} \    %{Qy:} %{!Qn:-Qy}"
end_define

begin_undef
undef|#
directive|undef
name|MD_STARTFILE_PREFIX
end_undef

begin_define
define|#
directive|define
name|MD_STARTFILE_PREFIX
value|"/usr/lib/sparcv9/"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SPARC_BI_ARCH */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

