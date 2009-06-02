begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  This is a clang style test case for checking that preprocessor defines match gcc. */
end_comment

begin_comment
comment|/* RUN: for arch in -m32 -m64; do \ RUN:   for lang in -std=gnu89 -ansi -std=c99 -std=gnu99; do \ RUN:     for input in c objective-c; do \ RUN:       for opts in "-O0" "-O1 -dynamic" "-O2 -static" "-Os"; do     \ RUN:         echo "-- $arch, $lang, $input, $opts --"; \ RUN:         for cc in 0 1; do \ RUN:           if [ "$cc" == 0 ]; then \ RUN:             cc_prog=clang; \ RUN:             output=%t0; \ RUN:           else \ RUN:             cc_prog=gcc; \ RUN:             output=%t1; \ RUN:           fi; \ RUN:           $cc_prog $arch $lang $opts -march=core2 -dM -E -x $input %s | sort> $output; \ RUN:          done; \ RUN:          if (! diff %t0 %t1); then exit 1; fi; \ RUN:       done; \ RUN:     done; \ RUN:   done; \ RUN: done; */
end_comment

begin_comment
comment|/* We don't care about this difference */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__PIC__
end_ifdef

begin_if
if|#
directive|if
name|__PIC__
operator|==
literal|1
end_if

begin_undef
undef|#
directive|undef
name|__PIC__
end_undef

begin_undef
undef|#
directive|undef
name|__pic__
end_undef

begin_define
define|#
directive|define
name|__PIC__
value|2
end_define

begin_define
define|#
directive|define
name|__pic__
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Undefine things we don't expect to match. */
end_comment

begin_undef
undef|#
directive|undef
name|__core2
end_undef

begin_undef
undef|#
directive|undef
name|__core2__
end_undef

begin_undef
undef|#
directive|undef
name|__SSSE3__
end_undef

begin_comment
comment|/* Undefine things we don't expect to match. */
end_comment

begin_undef
undef|#
directive|undef
name|__DEC_EVAL_METHOD__
end_undef

begin_undef
undef|#
directive|undef
name|__INT16_TYPE__
end_undef

begin_undef
undef|#
directive|undef
name|__INT32_TYPE__
end_undef

begin_undef
undef|#
directive|undef
name|__INT64_TYPE__
end_undef

begin_undef
undef|#
directive|undef
name|__INT8_TYPE__
end_undef

begin_undef
undef|#
directive|undef
name|__SSP__
end_undef

begin_undef
undef|#
directive|undef
name|__APPLE_CC__
end_undef

begin_undef
undef|#
directive|undef
name|__VERSION__
end_undef

begin_undef
undef|#
directive|undef
name|__clang__
end_undef

begin_undef
undef|#
directive|undef
name|__llvm__
end_undef

begin_undef
undef|#
directive|undef
name|__nocona
end_undef

begin_undef
undef|#
directive|undef
name|__nocona__
end_undef

begin_undef
undef|#
directive|undef
name|__k8
end_undef

begin_undef
undef|#
directive|undef
name|__k8__
end_undef

begin_undef
undef|#
directive|undef
name|__tune_nocona__
end_undef

begin_undef
undef|#
directive|undef
name|__tune_core2__
end_undef

begin_undef
undef|#
directive|undef
name|__POINTER_WIDTH__
end_undef

begin_undef
undef|#
directive|undef
name|__INTPTR_TYPE__
end_undef

begin_undef
undef|#
directive|undef
name|__NO_MATH_INLINES
end_undef

begin_undef
undef|#
directive|undef
name|__DEC128_DEN__
end_undef

begin_undef
undef|#
directive|undef
name|__DEC128_EPSILON__
end_undef

begin_undef
undef|#
directive|undef
name|__DEC128_MANT_DIG__
end_undef

begin_undef
undef|#
directive|undef
name|__DEC128_MAX_EXP__
end_undef

begin_undef
undef|#
directive|undef
name|__DEC128_MAX__
end_undef

begin_undef
undef|#
directive|undef
name|__DEC128_MIN_EXP__
end_undef

begin_undef
undef|#
directive|undef
name|__DEC128_MIN__
end_undef

begin_undef
undef|#
directive|undef
name|__DEC32_DEN__
end_undef

begin_undef
undef|#
directive|undef
name|__DEC32_EPSILON__
end_undef

begin_undef
undef|#
directive|undef
name|__DEC32_MANT_DIG__
end_undef

begin_undef
undef|#
directive|undef
name|__DEC32_MAX_EXP__
end_undef

begin_undef
undef|#
directive|undef
name|__DEC32_MAX__
end_undef

begin_undef
undef|#
directive|undef
name|__DEC32_MIN_EXP__
end_undef

begin_undef
undef|#
directive|undef
name|__DEC32_MIN__
end_undef

begin_undef
undef|#
directive|undef
name|__DEC64_DEN__
end_undef

begin_undef
undef|#
directive|undef
name|__DEC64_EPSILON__
end_undef

begin_undef
undef|#
directive|undef
name|__DEC64_MANT_DIG__
end_undef

begin_undef
undef|#
directive|undef
name|__DEC64_MAX_EXP__
end_undef

begin_undef
undef|#
directive|undef
name|__DEC64_MAX__
end_undef

begin_undef
undef|#
directive|undef
name|__DEC64_MIN_EXP__
end_undef

begin_undef
undef|#
directive|undef
name|__DEC64_MIN__
end_undef

end_unit

