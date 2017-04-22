begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===----------------------------------------------------------------------===////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is dual licensed under the MIT and the University of Illinois Open
end_comment

begin_comment
comment|// Source Licenses. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===////
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ATOMIC_SUPPORT_H
end_ifndef

begin_define
define|#
directive|define
name|ATOMIC_SUPPORT_H
end_define

begin_include
include|#
directive|include
file|"__config"
end_include

begin_include
include|#
directive|include
file|"memory"
end_include

begin_comment
comment|// for __libcpp_relaxed_load
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__clang__
argument_list|)
operator|&&
name|__has_builtin
argument_list|(
name|__atomic_load_n
argument_list|)
expr|\
operator|&&
name|__has_builtin
argument_list|(
name|__atomic_store_n
argument_list|)
expr|\
operator|&&
name|__has_builtin
argument_list|(
name|__atomic_add_fetch
argument_list|)
expr|\
operator|&&
name|__has_builtin
argument_list|(
name|__atomic_compare_exchange_n
argument_list|)
expr|\
operator|&&
name|defined
argument_list|(
name|__ATOMIC_RELAXED
argument_list|)
expr|\
operator|&&
name|defined
argument_list|(
name|__ATOMIC_CONSUME
argument_list|)
expr|\
operator|&&
name|defined
argument_list|(
name|__ATOMIC_ACQUIRE
argument_list|)
expr|\
operator|&&
name|defined
argument_list|(
name|__ATOMIC_RELEASE
argument_list|)
expr|\
operator|&&
name|defined
argument_list|(
name|__ATOMIC_ACQ_REL
argument_list|)
expr|\
operator|&&
name|defined
argument_list|(
name|__ATOMIC_SEQ_CST
argument_list|)
end_if

begin_define
define|#
directive|define
name|_LIBCPP_HAS_ATOMIC_BUILTINS
end_define

begin_elif
elif|#
directive|elif
operator|!
name|defined
argument_list|(
name|__clang__
argument_list|)
operator|&&
name|defined
argument_list|(
name|_GNUC_VER
argument_list|)
operator|&&
name|_GNUC_VER
operator|>=
literal|407
end_elif

begin_define
define|#
directive|define
name|_LIBCPP_HAS_ATOMIC_BUILTINS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_LIBCPP_HAS_ATOMIC_BUILTINS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_LIBCPP_HAS_NO_THREADS
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_LIBCPP_MSVC
argument_list|)
end_if

begin_macro
name|_LIBCPP_WARNING
argument_list|(
literal|"Building libc++ without __atomic builtins is unsupported"
argument_list|)
end_macro

begin_else
else|#
directive|else
end_else

begin_warning
warning|#
directive|warning
warning|Building libc++ without __atomic builtins is unsupported
end_warning

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|_LIBCPP_BEGIN_NAMESPACE_STD
name|namespace
block|{
if|#
directive|if
name|defined
argument_list|(
name|_LIBCPP_HAS_ATOMIC_BUILTINS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_LIBCPP_HAS_NO_THREADS
argument_list|)
enum|enum
name|__libcpp_atomic_order
block|{
name|_AO_Relaxed
init|=
name|__ATOMIC_RELAXED
block|,
name|_AO_Consume
init|=
name|__ATOMIC_CONSUME
block|,
name|_AO_Acquire
init|=
name|__ATOMIC_ACQUIRE
block|,
name|_AO_Release
init|=
name|__ATOMIC_RELEASE
block|,
name|_AO_Acq_Rel
init|=
name|__ATOMIC_ACQ_REL
block|,
name|_AO_Seq
init|=
name|__ATOMIC_SEQ_CST
block|}
enum|;
name|template
operator|<
name|class
name|_ValueType
operator|,
name|class
name|_FromType
operator|>
specifier|inline
name|_LIBCPP_INLINE_VISIBILITY
name|void
name|__libcpp_atomic_store
argument_list|(
argument|_ValueType* __dest
argument_list|,
argument|_FromType __val
argument_list|,
argument|int __order = _AO_Seq
argument_list|)
block|{
name|__atomic_store_n
argument_list|(
name|__dest
argument_list|,
name|__val
argument_list|,
name|__order
argument_list|)
block|; }
name|template
operator|<
name|class
name|_ValueType
operator|,
name|class
name|_FromType
operator|>
specifier|inline
name|_LIBCPP_INLINE_VISIBILITY
name|void
name|__libcpp_relaxed_store
argument_list|(
argument|_ValueType* __dest
argument_list|,
argument|_FromType __val
argument_list|)
block|{
name|__atomic_store_n
argument_list|(
name|__dest
argument_list|,
name|__val
argument_list|,
name|_AO_Relaxed
argument_list|)
block|; }
name|template
operator|<
name|class
name|_ValueType
operator|>
specifier|inline
name|_LIBCPP_INLINE_VISIBILITY
name|_ValueType
name|__libcpp_atomic_load
argument_list|(
argument|_ValueType const* __val
argument_list|,
argument|int __order = _AO_Seq
argument_list|)
block|{
return|return
name|__atomic_load_n
argument_list|(
name|__val
argument_list|,
name|__order
argument_list|)
return|;
block|}
name|template
operator|<
name|class
name|_ValueType
operator|,
name|class
name|_AddType
operator|>
specifier|inline
name|_LIBCPP_INLINE_VISIBILITY
name|_ValueType
name|__libcpp_atomic_add
argument_list|(
argument|_ValueType* __val
argument_list|,
argument|_AddType __a
argument_list|,
argument|int __order = _AO_Seq
argument_list|)
block|{
return|return
name|__atomic_add_fetch
argument_list|(
name|__val
argument_list|,
name|__a
argument_list|,
name|__order
argument_list|)
return|;
block|}
name|template
operator|<
name|class
name|_ValueType
operator|>
specifier|inline
name|_LIBCPP_INLINE_VISIBILITY
name|bool
name|__libcpp_atomic_compare_exchange
argument_list|(
argument|_ValueType* __val
argument_list|,
argument|_ValueType* __expected
argument_list|,
argument|_ValueType __after
argument_list|,
argument|int __success_order = _AO_Seq
argument_list|,
argument|int __fail_order = _AO_Seq
argument_list|)
block|{
return|return
name|__atomic_compare_exchange_n
argument_list|(
name|__val
argument_list|,
name|__expected
argument_list|,
name|__after
argument_list|,
name|true
argument_list|,
name|__success_order
argument_list|,
name|__fail_order
argument_list|)
return|;
block|}
else|#
directive|else
comment|// _LIBCPP_HAS_NO_THREADS
enum|enum
name|__libcpp_atomic_order
block|{
name|_AO_Relaxed
block|,
name|_AO_Consume
block|,
name|_AO_Acquire
block|,
name|_AO_Release
block|,
name|_AO_Acq_Rel
block|,
name|_AO_Seq
block|}
enum|;
name|template
operator|<
name|class
name|_ValueType
operator|,
name|class
name|_FromType
operator|>
specifier|inline
name|_LIBCPP_INLINE_VISIBILITY
name|void
name|__libcpp_atomic_store
argument_list|(
argument|_ValueType* __dest
argument_list|,
argument|_FromType __val
argument_list|,
argument|int =
literal|0
argument_list|)
block|{
operator|*
name|__dest
operator|=
name|__val
block|; }
name|template
operator|<
name|class
name|_ValueType
operator|,
name|class
name|_FromType
operator|>
specifier|inline
name|_LIBCPP_INLINE_VISIBILITY
name|void
name|__libcpp_relaxed_store
argument_list|(
argument|_ValueType* __dest
argument_list|,
argument|_FromType __val
argument_list|)
block|{
operator|*
name|__dest
operator|=
name|__val
block|; }
name|template
operator|<
name|class
name|_ValueType
operator|>
specifier|inline
name|_LIBCPP_INLINE_VISIBILITY
name|_ValueType
name|__libcpp_atomic_load
argument_list|(
argument|_ValueType const* __val
argument_list|,
argument|int =
literal|0
argument_list|)
block|{
return|return
operator|*
name|__val
return|;
block|}
name|template
operator|<
name|class
name|_ValueType
operator|,
name|class
name|_AddType
operator|>
specifier|inline
name|_LIBCPP_INLINE_VISIBILITY
name|_ValueType
name|__libcpp_atomic_add
argument_list|(
argument|_ValueType* __val
argument_list|,
argument|_AddType __a
argument_list|,
argument|int =
literal|0
argument_list|)
block|{
return|return
operator|*
name|__val
operator|+=
name|__a
return|;
block|}
name|template
operator|<
name|class
name|_ValueType
operator|>
specifier|inline
name|_LIBCPP_INLINE_VISIBILITY
name|bool
name|__libcpp_atomic_compare_exchange
argument_list|(
argument|_ValueType* __val
argument_list|,
argument|_ValueType* __expected
argument_list|,
argument|_ValueType __after
argument_list|,
argument|int =
literal|0
argument_list|,
argument|int =
literal|0
argument_list|)
block|{
if|if
condition|(
operator|*
name|__val
operator|==
operator|*
name|__expected
condition|)
block|{
operator|*
name|__val
operator|=
name|__after
expr_stmt|;
return|return
name|true
return|;
block|}
operator|*
name|__expected
operator|=
operator|*
name|__val
expr_stmt|;
return|return
name|false
return|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _LIBCPP_HAS_NO_THREADS
end_comment

begin_comment
unit|}
comment|// end namespace
end_comment

begin_endif
unit|_LIBCPP_END_NAMESPACE_STD
endif|#
directive|endif
end_endif

begin_comment
comment|// ATOMIC_SUPPORT_H
end_comment

end_unit

