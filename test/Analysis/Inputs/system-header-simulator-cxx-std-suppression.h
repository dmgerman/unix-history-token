begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// This is a fake system header with divide-by-zero bugs introduced in
end_comment

begin_comment
comment|// c++ std library functions. We use these bugs to test hard-coded
end_comment

begin_comment
comment|// suppression of diagnostics within standard library functions that are known
end_comment

begin_comment
comment|// to produce false positives.
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|system_header
end_pragma

begin_typedef
typedef|typedef
name|unsigned
name|char
name|uint8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__typeof__
argument_list|(
argument|sizeof(int)
argument_list|)
name|size_t
expr_stmt|;
end_typedef

begin_function_decl
name|void
modifier|*
name|memmove
parameter_list|(
name|void
modifier|*
name|s1
parameter_list|,
specifier|const
name|void
modifier|*
name|s2
parameter_list|,
name|size_t
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|namespace
name|std
block|{
name|template
operator|<
name|class
name|_Tp
operator|>
name|class
name|allocator
block|{
name|public
operator|:
name|void
name|deallocate
argument_list|(
argument|void *p
argument_list|)
block|{
operator|::
name|delete
name|p
block|;     }
block|}
expr_stmt|;
name|template
operator|<
name|class
name|_Alloc
operator|>
name|class
name|allocator_traits
block|{
name|public
operator|:
specifier|static
name|void
name|deallocate
argument_list|(
argument|void *p
argument_list|)
block|{
name|_Alloc
argument_list|()
operator|.
name|deallocate
argument_list|(
name|p
argument_list|)
block|;     }
block|}
expr_stmt|;
name|template
operator|<
name|class
name|_Tp
operator|,
name|class
name|_Alloc
operator|>
name|class
name|__list_imp
block|{}
expr_stmt|;
name|template
operator|<
name|class
name|_Tp
operator|,
name|class
name|_Alloc
operator|=
name|allocator
operator|<
name|_Tp
operator|>
expr|>
name|class
name|list
operator|:
name|private
name|__list_imp
operator|<
name|_Tp
operator|,
name|_Alloc
operator|>
block|{
name|public
operator|:
name|void
name|pop_front
argument_list|()
block|{
comment|// Fake use-after-free.
comment|// No warning is expected as we are suppressing warning coming
comment|// out of std::list.
name|int
name|z
operator|=
literal|0
block|;
name|z
operator|=
literal|5
operator|/
name|z
block|;     }
name|bool
name|empty
argument_list|()
specifier|const
block|;   }
expr_stmt|;
comment|// basic_string
name|template
operator|<
name|class
name|_CharT
operator|,
name|class
name|_Alloc
operator|=
name|allocator
operator|<
name|_CharT
operator|>
expr|>
name|class
name|__attribute__
argument_list|(
argument|(__type_visibility__(
literal|"default"
argument|))
argument_list|)
name|basic_string
block|{
name|bool
name|isLong
block|;
expr|union
block|{
name|_CharT
name|localStorage
index|[
literal|4
index|]
block|;
name|_CharT
operator|*
name|externalStorage
block|;
name|void
name|assignExternal
argument_list|(
argument|_CharT *newExternal
argument_list|)
block|{
name|externalStorage
operator|=
name|newExternal
block|;       }
block|}
name|storage
block|;
typedef|typedef
name|allocator_traits
operator|<
name|_Alloc
operator|>
name|__alloc_traits
expr_stmt|;
name|public
operator|:
name|basic_string
argument_list|()
expr_stmt|;
name|void
name|push_back
parameter_list|(
name|int
name|c
parameter_list|)
block|{
comment|// Fake error trigger.
comment|// No warning is expected as we are suppressing warning coming
comment|// out of std::basic_string.
name|int
name|z
init|=
literal|0
decl_stmt|;
name|z
operator|=
literal|5
operator|/
name|z
expr_stmt|;
block|}
name|_CharT
modifier|*
name|getBuffer
parameter_list|()
block|{
return|return
name|isLong
condition|?
name|storage
operator|.
name|externalStorage
else|:
name|storage
operator|.
name|localStorage
return|;
block|}
name|basic_string
operator|&
name|operator
operator|+=
operator|(
name|int
name|c
operator|)
block|{
comment|// Fake deallocate stack-based storage.
comment|// No warning is expected as we are suppressing warnings within
comment|// std::basic_string.
name|__alloc_traits
operator|::
name|deallocate
argument_list|(
name|getBuffer
argument_list|()
argument_list|)
block|;     }
name|basic_string
operator|&
name|operator
operator|=
operator|(
specifier|const
name|basic_string
operator|&
name|other
operator|)
block|{
comment|// Fake deallocate stack-based storage, then use the variable in the
comment|// same union.
comment|// No warning is expected as we are suppressing warnings within
comment|// std::basic_string.
name|__alloc_traits
operator|::
name|deallocate
argument_list|(
name|getBuffer
argument_list|()
argument_list|)
block|;
name|storage
operator|.
name|assignExternal
argument_list|(
argument|new _CharT[
literal|4
argument|]
argument_list|)
block|;     }
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|_Engine
operator|,
name|class
name|_UIntType
operator|>
name|class
name|__independent_bits_engine
block|{
name|public
operator|:
comment|// constructors and seeding functions
name|__independent_bits_engine
argument_list|(
argument|_Engine& __e
argument_list|,
argument|size_t __w
argument_list|)
block|; }
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|_Engine
operator|,
name|class
name|_UIntType
operator|>
name|__independent_bits_engine
operator|<
name|_Engine
operator|,
name|_UIntType
operator|>
operator|::
name|__independent_bits_engine
argument_list|(
argument|_Engine& __e
argument_list|,
argument|size_t __w
argument_list|)
block|{
comment|// Fake error trigger.
comment|// No warning is expected as we are suppressing warning coming
comment|// out of std::__independent_bits_engine.
name|int
name|z
operator|=
literal|0
block|;
name|z
operator|=
literal|5
operator|/
name|z
block|; }
end_expr_stmt

begin_if
if|#
directive|if
name|__has_feature
argument_list|(
name|cxx_decltype
argument_list|)
end_if

begin_typedef
typedef|typedef
name|decltype
argument_list|(
argument|nullptr
argument_list|)
name|nullptr_t
expr_stmt|;
end_typedef

begin_expr_stmt
name|template
operator|<
name|class
name|_Tp
operator|>
name|class
name|shared_ptr
block|{
name|public
operator|:
name|constexpr
name|shared_ptr
argument_list|(
name|nullptr_t
argument_list|)
block|;
name|explicit
name|shared_ptr
argument_list|(
name|_Tp
operator|*
name|__p
argument_list|)
block|;
name|shared_ptr
argument_list|(
argument|shared_ptr&& __r
argument_list|)
block|{ }
operator|~
name|shared_ptr
argument_list|()
block|;
name|shared_ptr
operator|&
name|operator
operator|=
operator|(
name|shared_ptr
operator|&&
name|__r
operator|)
block|{
comment|// Fake error trigger.
comment|// No warning is expected as we are suppressing warning coming
comment|// out of std::shared_ptr.
name|int
name|z
operator|=
literal|0
block|;
name|z
operator|=
literal|5
operator|/
name|z
block|;   }
block|}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|_Tp
operator|>
specifier|inline
name|constexpr
name|shared_ptr
operator|<
name|_Tp
operator|>
operator|::
name|shared_ptr
argument_list|(
argument|nullptr_t
argument_list|)
block|{ }
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __has_feature(cxx_decltype)
end_comment

unit|}
end_unit

