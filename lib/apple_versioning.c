begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ===-- apple_versioning.c - Adds versioning symbols for ld ---------------===  *  *                     The LLVM Compiler Infrastructure  *  * This file is dual licensed under the MIT and the University of Illinois Open  * Source Licenses. See LICENSE.TXT for details.  *  * ===----------------------------------------------------------------------===  */
end_comment

begin_if
if|#
directive|if
name|__APPLE__
end_if

begin_if
if|#
directive|if
name|__arm__
end_if

begin_define
define|#
directive|define
name|NOT_HERE_BEFORE_10_6
parameter_list|(
name|sym
parameter_list|)
end_define

begin_elif
elif|#
directive|elif
name|__ppc__
end_elif

begin_define
define|#
directive|define
name|NOT_HERE_BEFORE_10_6
parameter_list|(
name|sym
parameter_list|)
define|\
value|extern const char sym##_tmp3 __asm("$ld$hide$os10.3$_" #sym ); \             __attribute__((visibility("default"))) const char sym##_tmp3 = 0; \          extern const char sym##_tmp4 __asm("$ld$hide$os10.4$_" #sym ); \             __attribute__((visibility("default"))) const char sym##_tmp4 = 0; \         extern const char sym##_tmp5 __asm("$ld$hide$os10.5$_" #sym ); \             __attribute__((visibility("default"))) const char sym##_tmp5 = 0;
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NOT_HERE_BEFORE_10_6
parameter_list|(
name|sym
parameter_list|)
define|\
value|extern const char sym##_tmp4 __asm("$ld$hide$os10.4$_" #sym ); \             __attribute__((visibility("default"))) const char sym##_tmp4 = 0; \         extern const char sym##_tmp5 __asm("$ld$hide$os10.5$_" #sym ); \             __attribute__((visibility("default"))) const char sym##_tmp5 = 0;
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ppc__ */
end_comment

begin_comment
comment|/* Symbols in libSystem.dylib in 10.6 and later,   *  but are in libgcc_s.dylib in earlier versions  */
end_comment

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__absvdi2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__absvsi2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__absvti2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__addvdi3
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__addvsi3
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__addvti3
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__ashldi3
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__ashlti3
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__ashrdi3
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__ashrti3
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__clear_cache
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__clzdi2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__clzsi2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__clzti2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__cmpdi2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__cmpti2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__ctzdi2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__ctzsi2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__ctzti2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__divdc3
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__divdi3
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__divsc3
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__divtc3
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__divti3
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__divxc3
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__enable_execute_stack
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__ffsdi2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__ffsti2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__fixdfdi
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__fixdfti
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__fixsfdi
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__fixsfti
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__fixtfdi
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__fixunsdfdi
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__fixunsdfsi
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__fixunsdfti
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__fixunssfdi
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__fixunssfsi
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__fixunssfti
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__fixunstfdi
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__fixunsxfdi
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__fixunsxfsi
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__fixunsxfti
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__fixxfdi
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__fixxfti
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__floatdidf
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__floatdisf
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__floatditf
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__floatdixf
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__floattidf
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__floattisf
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__floattixf
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__floatundidf
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__floatundisf
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__floatunditf
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__floatundixf
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__floatuntidf
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__floatuntisf
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__floatuntixf
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__gcc_personality_v0
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__lshrdi3
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__lshrti3
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__moddi3
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__modti3
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__muldc3
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__muldi3
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__mulsc3
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__multc3
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__multi3
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__mulvdi3
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__mulvsi3
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__mulvti3
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__mulxc3
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__negdi2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__negti2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__negvdi2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__negvsi2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__negvti2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__paritydi2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__paritysi2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__parityti2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__popcountdi2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__popcountsi2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__popcountti2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__powidf2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__powisf2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__powitf2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__powixf2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__subvdi3
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__subvsi3
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__subvti3
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__ucmpdi2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__ucmpti2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__udivdi3
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__udivmoddi4
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__udivmodti4
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__udivti3
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__umoddi3
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__umodti3
argument_list|)
end_macro

begin_if
if|#
directive|if
name|__ppc__
end_if

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__gcc_qadd
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__gcc_qdiv
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__gcc_qmul
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__gcc_qsub
argument_list|)
end_macro

begin_macro
name|NOT_HERE_BEFORE_10_6
argument_list|(
argument|__trampoline_setup
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ppc__ */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !__APPLE__ */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|avoid_empty_file
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__APPLE__*/
end_comment

end_unit

