begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GCC, for bi-arch SPARC    running Solaris 2 using the system assembler and linker.  */
end_comment

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

begin_define
define|#
directive|define
name|AS_SPARC64_FLAG
value|"-xarch=v9"
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

begin_if
if|#
directive|if
name|TARGET_CPU_DEFAULT
operator|==
name|TARGET_CPU_ultrasparc3
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
value|"-xarch=v8plusb"
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
value|AS_SPARC64_FLAG "b"
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
value|"\ %{mcypress:} \ %{msparclite|mf930|mf934:-D__sparclite__} \ %{mv8:" DEF_ARCH32_SPEC("-D__sparcv8") "} \ %{msupersparc:-D__supersparc__ " DEF_ARCH32_SPEC("-D__sparcv8") "} \ %{mcpu=sparclet|mcpu=tsc701:-D__sparclet__} \ %{mcpu=sparclite|mcpu-f930|mcpu=f934:-D__sparclite__} \ %{mcpu=v8:" DEF_ARCH32_SPEC("-D__sparcv8") "} \ %{mcpu=supersparc:-D__supersparc__ " DEF_ARCH32_SPEC("-D__sparcv8") "} \ %{mcpu=v9|mcpu=ultrasparc|mcpu=ultrasparc3:" DEF_ARCH32_SPEC("-D__sparcv8") "} \ %{!mcpu*:%{!mcypress:%{!msparclite:%{!mf930:%{!mf934:%{!mv8:%{!msupersparc:%(cpp_cpu_default)}}}}}}} \ "
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
value|"\ %{mcpu=v9:" DEF_ARCH32_SPEC("-xarch=v8plus") DEF_ARCH64_SPEC(AS_SPARC64_FLAG) "} \ %{mcpu=ultrasparc:" DEF_ARCH32_SPEC("-xarch=v8plusa") DEF_ARCH64_SPEC(AS_SPARC64_FLAG "a") "} \ %{mcpu=ultrasparc3:" DEF_ARCH32_SPEC("-xarch=v8plusb") DEF_ARCH64_SPEC(AS_SPARC64_FLAG "b") "} \ %{!mcpu=ultrasparc3:%{!mcpu=ultrasparc:%{!mcpu=v9:%{mcpu*:" DEF_ARCH32_SPEC("-xarch=v8") DEF_ARCH64_SPEC(AS_SPARC64_FLAG) "}}}} \ %{!mcpu*:%(asm_cpu_default)} \ "
end_define

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
value|""
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
value|"-D__arch64__ -D__sparcv9"
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
value|{ "startfile_arch",	 STARTFILE_ARCH_SPEC },		  \   { "link_arch32",       LINK_ARCH32_SPEC },              \   { "link_arch64",       LINK_ARCH64_SPEC },              \   { "link_arch_default", LINK_ARCH_DEFAULT_SPEC },	  \   { "link_arch",	 LINK_ARCH_SPEC },
end_define

begin_comment
comment|/*  * This should be the same as in sol2.h, except with "/sparcv9"  * appended to the paths and /usr/ccs/lib is no longer necessary  */
end_comment

begin_define
define|#
directive|define
name|LINK_ARCH64_SPEC_BASE
define|\
value|"%{mcmodel=medlow:-M /usr/lib/ld/sparcv9/map.below4G} \    %{G:-G} \    %{YP,*} \    %{R*} \    %{compat-bsd: \      %{!YP,*:%{p|pg:-Y P,/usr/ucblib/sparcv9:/usr/lib/libp/sparcv9:/usr/lib/sparcv9} \        %{!p:%{!pg:-Y P,/usr/ucblib/sparcv9:/usr/lib/sparcv9}}} \      -R /usr/ucblib/sparcv9} \    %{!compat-bsd: \      %{!YP,*:%{p|pg:-Y P,/usr/lib/libp/sparcv9:/usr/lib/sparcv9} \        %{!p:%{!pg:-Y P,/usr/lib/sparcv9}}}}"
end_define

begin_define
define|#
directive|define
name|LINK_ARCH64_SPEC
value|LINK_ARCH64_SPEC_BASE
end_define

begin_undef
undef|#
directive|undef
name|LINK_ARCH_SPEC
end_undef

begin_if
if|#
directive|if
name|DISABLE_MULTILIB
end_if

begin_if
if|#
directive|if
name|DEFAULT_ARCH32_P
end_if

begin_define
define|#
directive|define
name|LINK_ARCH_SPEC
value|"\ %{m32:%(link_arch32)} \ %{m64:%edoes not support multilib} \ %{!m32:%{!m64:%(link_arch_default)}} \ "
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LINK_ARCH_SPEC
value|"\ %{m32:%edoes not support multilib} \ %{m64:%(link_arch64)} \ %{!m32:%{!m64:%(link_arch_default)}} \ "
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LINK_ARCH_SPEC
value|"\ %{m32:%(link_arch32)} \ %{m64:%(link_arch64)} \ %{!m32:%{!m64:%(link_arch_default)}} \ "
end_define

begin_endif
endif|#
directive|endif
end_endif

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
value|"\ %{sun4:} %{target:} \ %{mcypress:-mcpu=cypress} \ %{msparclite:-mcpu=sparclite} %{mf930:-mcpu=f930} %{mf934:-mcpu=f934} \ %{mv8:-mcpu=v8} %{msupersparc:-mcpu=supersparc} \ %{m32:%{m64:%emay not use both -m32 and -m64}} \ %{m64:-mptr64 -mstack-bias -mno-v8plus \   %{!mcpu*:%{!mcypress:%{!msparclite:%{!mf930:%{!mf934:%{!mv8*:%{!msupersparc:-mcpu=v9}}}}}}}} \ "
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CC1_SPEC
value|"\ %{sun4:} %{target:} \ %{mcypress:-mcpu=cypress} \ %{msparclite:-mcpu=sparclite} %{mf930:-mcpu=f930} %{mf934:-mcpu=f934} \ %{mv8:-mcpu=v8} %{msupersparc:-mcpu=supersparc} \ %{m32:%{m64:%emay not use both -m32 and -m64}} \ %{m32:-mptr32 -mno-stack-bias \   %{!mcpu*:%{!mcypress:%{!msparclite:%{!mf930:%{!mf934:%{!mv8*:%{!msupersparc:-mcpu=cypress}}}}}}}} \ %{mv8plus:-m32 -mptr32 -mno-stack-bias \   %{!mcpu*:%{!mcypress:%{!msparclite:%{!mf930:%{!mf934:%{!mv8:%{!msupersparc:-mcpu=v9}}}}}}}} \ "
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Support for a compile-time default CPU, et cetera.  The rules are:    --with-cpu is ignored if -mcpu is specified.    --with-tune is ignored if -mtune is specified.    --with-float is ignored if -mhard-float, -msoft-float, -mfpu, or -mno-fpu      are specified.    In the SPARC_BI_ARCH compiler we cannot pass %{!mcpu=*:-mcpu=%(VALUE)}    here, otherwise say -mcpu=v7 would be passed even when -m64.    CC1_SPEC above takes care of this instead.  */
end_comment

begin_undef
undef|#
directive|undef
name|OPTION_DEFAULT_SPECS
end_undef

begin_if
if|#
directive|if
name|DEFAULT_ARCH32_P
end_if

begin_define
define|#
directive|define
name|OPTION_DEFAULT_SPECS
define|\
value|{"cpu", "%{!m64:%{!mcpu=*:-mcpu=%(VALUE)}}" }, \   {"tune", "%{!mtune=*:-mtune=%(VALUE)}" }, \   {"float", "%{!msoft-float:%{!mhard-float:%{!fpu:%{!no-fpu:-m%(VALUE)-float}}}}" }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|OPTION_DEFAULT_SPECS
define|\
value|{"cpu", "%{!m32:%{!mcpu=*:-mcpu=%(VALUE)}}" }, \   {"tune", "%{!mtune=*:-mtune=%(VALUE)}" }, \   {"float", "%{!msoft-float:%{!mhard-float:%{!fpu:%{!no-fpu:-m%(VALUE)-float}}}}" }
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

begin_undef
undef|#
directive|undef
name|PREFERRED_DEBUGGING_TYPE
end_undef

begin_define
define|#
directive|define
name|PREFERRED_DEBUGGING_TYPE
value|DWARF2_DEBUG
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_AS_GDWARF2_DEBUG_FLAG
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_AS_GSTABS_DEBUG_FLAG
argument_list|)
end_if

begin_define
define|#
directive|define
name|ASM_DEBUG_SPEC
value|"%{gstabs*:--gstabs}%{!gstabs*:%{g*:--gdwarf2}}"
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

