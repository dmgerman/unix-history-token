begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ===-- apple_versioning.c - Adds versioning symbols for ld ---------------===  *  *                     The LLVM Compiler Infrastructure  *  * This file is dual licensed under the MIT and the University of Illinois Open  * Source Licenses. See LICENSE.TXT for details.  *  * ===----------------------------------------------------------------------===  */
end_comment

begin_if
if|#
directive|if
name|__APPLE__
end_if

begin_include
include|#
directive|include
file|<Availability.h>
end_include

begin_if
if|#
directive|if
name|__IPHONE_OS_VERSION_MIN_REQUIRED
end_if

begin_define
define|#
directive|define
name|NOT_HERE_BEFORE_10_6
parameter_list|(
name|sym
parameter_list|)
end_define

begin_define
define|#
directive|define
name|NOT_HERE_IN_10_8_AND_EARLIER
parameter_list|(
name|sym
parameter_list|)
define|\
value|extern const char sym##_tmp61 __asm("$ld$hide$os6.1$_" #sym ); \             __attribute__((visibility("default"))) const char sym##_tmp61 = 0; \         extern const char sym##_tmp60 __asm("$ld$hide$os6.0$_" #sym ); \             __attribute__((visibility("default"))) const char sym##_tmp60 = 0; \         extern const char sym##_tmp51 __asm("$ld$hide$os5.1$_" #sym ); \             __attribute__((visibility("default"))) const char sym##_tmp51 = 0; \         extern const char sym##_tmp50 __asm("$ld$hide$os5.0$_" #sym ); \             __attribute__((visibility("default"))) const char sym##_tmp50 = 0;
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

begin_define
define|#
directive|define
name|NOT_HERE_IN_10_8_AND_EARLIER
parameter_list|(
name|sym
parameter_list|)
define|\
value|extern const char sym##_tmp8 __asm("$ld$hide$os10.8$_" #sym ); \             __attribute__((visibility("default"))) const char sym##_tmp8 = 0; \         extern const char sym##_tmp7 __asm("$ld$hide$os10.7$_" #sym ); \             __attribute__((visibility("default"))) const char sym##_tmp7 = 0; \         extern const char sym##_tmp6 __asm("$ld$hide$os10.6$_" #sym ); \             __attribute__((visibility("default"))) const char sym##_tmp6 = 0;
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_macro
name|NOT_HERE_IN_10_8_AND_EARLIER
argument_list|(
argument|__atomic_compare_exchange
argument_list|)
end_macro

begin_macro
name|NOT_HERE_IN_10_8_AND_EARLIER
argument_list|(
argument|__atomic_compare_exchange_1
argument_list|)
end_macro

begin_macro
name|NOT_HERE_IN_10_8_AND_EARLIER
argument_list|(
argument|__atomic_compare_exchange_2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_IN_10_8_AND_EARLIER
argument_list|(
argument|__atomic_compare_exchange_4
argument_list|)
end_macro

begin_macro
name|NOT_HERE_IN_10_8_AND_EARLIER
argument_list|(
argument|__atomic_compare_exchange_8
argument_list|)
end_macro

begin_macro
name|NOT_HERE_IN_10_8_AND_EARLIER
argument_list|(
argument|__atomic_exchange
argument_list|)
end_macro

begin_macro
name|NOT_HERE_IN_10_8_AND_EARLIER
argument_list|(
argument|__atomic_exchange_1
argument_list|)
end_macro

begin_macro
name|NOT_HERE_IN_10_8_AND_EARLIER
argument_list|(
argument|__atomic_exchange_2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_IN_10_8_AND_EARLIER
argument_list|(
argument|__atomic_exchange_4
argument_list|)
end_macro

begin_macro
name|NOT_HERE_IN_10_8_AND_EARLIER
argument_list|(
argument|__atomic_exchange_8
argument_list|)
end_macro

begin_macro
name|NOT_HERE_IN_10_8_AND_EARLIER
argument_list|(
argument|__atomic_fetch_add_1
argument_list|)
end_macro

begin_macro
name|NOT_HERE_IN_10_8_AND_EARLIER
argument_list|(
argument|__atomic_fetch_add_2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_IN_10_8_AND_EARLIER
argument_list|(
argument|__atomic_fetch_add_4
argument_list|)
end_macro

begin_macro
name|NOT_HERE_IN_10_8_AND_EARLIER
argument_list|(
argument|__atomic_fetch_add_8
argument_list|)
end_macro

begin_macro
name|NOT_HERE_IN_10_8_AND_EARLIER
argument_list|(
argument|__atomic_fetch_and_1
argument_list|)
end_macro

begin_macro
name|NOT_HERE_IN_10_8_AND_EARLIER
argument_list|(
argument|__atomic_fetch_and_2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_IN_10_8_AND_EARLIER
argument_list|(
argument|__atomic_fetch_and_4
argument_list|)
end_macro

begin_macro
name|NOT_HERE_IN_10_8_AND_EARLIER
argument_list|(
argument|__atomic_fetch_and_8
argument_list|)
end_macro

begin_macro
name|NOT_HERE_IN_10_8_AND_EARLIER
argument_list|(
argument|__atomic_fetch_or_1
argument_list|)
end_macro

begin_macro
name|NOT_HERE_IN_10_8_AND_EARLIER
argument_list|(
argument|__atomic_fetch_or_2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_IN_10_8_AND_EARLIER
argument_list|(
argument|__atomic_fetch_or_4
argument_list|)
end_macro

begin_macro
name|NOT_HERE_IN_10_8_AND_EARLIER
argument_list|(
argument|__atomic_fetch_or_8
argument_list|)
end_macro

begin_macro
name|NOT_HERE_IN_10_8_AND_EARLIER
argument_list|(
argument|__atomic_fetch_sub_1
argument_list|)
end_macro

begin_macro
name|NOT_HERE_IN_10_8_AND_EARLIER
argument_list|(
argument|__atomic_fetch_sub_2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_IN_10_8_AND_EARLIER
argument_list|(
argument|__atomic_fetch_sub_4
argument_list|)
end_macro

begin_macro
name|NOT_HERE_IN_10_8_AND_EARLIER
argument_list|(
argument|__atomic_fetch_sub_8
argument_list|)
end_macro

begin_macro
name|NOT_HERE_IN_10_8_AND_EARLIER
argument_list|(
argument|__atomic_fetch_xor_1
argument_list|)
end_macro

begin_macro
name|NOT_HERE_IN_10_8_AND_EARLIER
argument_list|(
argument|__atomic_fetch_xor_2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_IN_10_8_AND_EARLIER
argument_list|(
argument|__atomic_fetch_xor_4
argument_list|)
end_macro

begin_macro
name|NOT_HERE_IN_10_8_AND_EARLIER
argument_list|(
argument|__atomic_fetch_xor_8
argument_list|)
end_macro

begin_macro
name|NOT_HERE_IN_10_8_AND_EARLIER
argument_list|(
argument|__atomic_load
argument_list|)
end_macro

begin_macro
name|NOT_HERE_IN_10_8_AND_EARLIER
argument_list|(
argument|__atomic_load_1
argument_list|)
end_macro

begin_macro
name|NOT_HERE_IN_10_8_AND_EARLIER
argument_list|(
argument|__atomic_load_2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_IN_10_8_AND_EARLIER
argument_list|(
argument|__atomic_load_4
argument_list|)
end_macro

begin_macro
name|NOT_HERE_IN_10_8_AND_EARLIER
argument_list|(
argument|__atomic_load_8
argument_list|)
end_macro

begin_macro
name|NOT_HERE_IN_10_8_AND_EARLIER
argument_list|(
argument|__atomic_store
argument_list|)
end_macro

begin_macro
name|NOT_HERE_IN_10_8_AND_EARLIER
argument_list|(
argument|__atomic_store_1
argument_list|)
end_macro

begin_macro
name|NOT_HERE_IN_10_8_AND_EARLIER
argument_list|(
argument|__atomic_store_2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_IN_10_8_AND_EARLIER
argument_list|(
argument|__atomic_store_4
argument_list|)
end_macro

begin_macro
name|NOT_HERE_IN_10_8_AND_EARLIER
argument_list|(
argument|__atomic_store_8
argument_list|)
end_macro

begin_if
if|#
directive|if
name|__arm__
operator|&&
name|__DYNAMIC__
end_if

begin_define
define|#
directive|define
name|NOT_HERE_UNTIL_AFTER_4_3
parameter_list|(
name|sym
parameter_list|)
define|\
value|extern const char sym##_tmp1 __asm("$ld$hide$os3.0$_" #sym ); \             __attribute__((visibility("default"))) const char sym##_tmp1 = 0; \         extern const char sym##_tmp2 __asm("$ld$hide$os3.1$_" #sym ); \             __attribute__((visibility("default"))) const char sym##_tmp2 = 0; \         extern const char sym##_tmp3 __asm("$ld$hide$os3.2$_" #sym ); \             __attribute__((visibility("default"))) const char sym##_tmp3 = 0; \         extern const char sym##_tmp4 __asm("$ld$hide$os4.0$_" #sym ); \             __attribute__((visibility("default"))) const char sym##_tmp4 = 0; \         extern const char sym##_tmp5 __asm("$ld$hide$os4.1$_" #sym ); \             __attribute__((visibility("default"))) const char sym##_tmp5 = 0; \         extern const char sym##_tmp6 __asm("$ld$hide$os4.2$_" #sym ); \             __attribute__((visibility("default"))) const char sym##_tmp6 = 0; \         extern const char sym##_tmp7 __asm("$ld$hide$os4.3$_" #sym ); \             __attribute__((visibility("default"))) const char sym##_tmp7 = 0;
end_define

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__absvdi2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__absvsi2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__adddf3
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__adddf3vfp
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__addsf3
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__addsf3vfp
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__addvdi3
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__addvsi3
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__ashldi3
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__ashrdi3
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__bswapdi2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__bswapsi2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__clzdi2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__clzsi2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__cmpdi2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__ctzdi2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__ctzsi2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__divdc3
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__divdf3
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__divdf3vfp
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__divdi3
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__divsc3
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__divsf3
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__divsf3vfp
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__divsi3
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__eqdf2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__eqdf2vfp
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__eqsf2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__eqsf2vfp
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__extendsfdf2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__extendsfdf2vfp
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__ffsdi2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__fixdfdi
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__fixdfsi
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__fixdfsivfp
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__fixsfdi
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__fixsfsi
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__fixsfsivfp
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__fixunsdfdi
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__fixunsdfsi
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__fixunsdfsivfp
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__fixunssfdi
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__fixunssfsi
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__fixunssfsivfp
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__floatdidf
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__floatdisf
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__floatsidf
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__floatsidfvfp
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__floatsisf
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__floatsisfvfp
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__floatundidf
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__floatundisf
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__floatunsidf
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__floatunsisf
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__floatunssidfvfp
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__floatunssisfvfp
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__gedf2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__gedf2vfp
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__gesf2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__gesf2vfp
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__gtdf2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__gtdf2vfp
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__gtsf2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__gtsf2vfp
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__ledf2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__ledf2vfp
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__lesf2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__lesf2vfp
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__lshrdi3
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__ltdf2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__ltdf2vfp
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__ltsf2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__ltsf2vfp
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__moddi3
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__modsi3
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__muldc3
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__muldf3
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__muldf3vfp
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__muldi3
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__mulsc3
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__mulsf3
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__mulsf3vfp
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__mulvdi3
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__mulvsi3
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__nedf2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__nedf2vfp
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__negdi2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__negvdi2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__negvsi2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__nesf2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__nesf2vfp
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__paritydi2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__paritysi2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__popcountdi2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__popcountsi2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__powidf2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__powisf2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__subdf3
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__subdf3vfp
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__subsf3
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__subsf3vfp
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__subvdi3
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__subvsi3
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__truncdfsf2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__truncdfsf2vfp
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__ucmpdi2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__udivdi3
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__udivmoddi4
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__udivsi3
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__umoddi3
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__umodsi3
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__unorddf2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__unorddf2vfp
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__unordsf2
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__unordsf2vfp
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__divmodsi4
argument_list|)
end_macro

begin_macro
name|NOT_HERE_UNTIL_AFTER_4_3
argument_list|(
argument|__udivmodsi4
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __arm__&& __DYNAMIC__
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

