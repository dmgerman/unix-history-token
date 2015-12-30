begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|UTILS_H
end_ifndef

begin_define
define|#
directive|define
name|UTILS_H
end_define

begin_function
specifier|inline
name|void
name|break_optimization
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|("" : : "r" (arg) : "memory");
block|}
end_function

begin_comment
comment|// Tests will instantiate this class to pad out bit sets to test out the
end_comment

begin_comment
comment|// various ways we can represent the bit set (32-bit inline, 64-bit inline,
end_comment

begin_comment
comment|// memory). Instantiating this class will trigger the instantiation of I
end_comment

begin_comment
comment|// templates with I virtual tables for classes deriving from T, I-2 of which
end_comment

begin_comment
comment|// will be of size sizeof(void*) * 5, 1 of which will be of size sizeof(void*)
end_comment

begin_comment
comment|// * 3, and 1 of which will be of size sizeof(void*) * 9. (Under the MS ABI
end_comment

begin_comment
comment|// each virtual table will be sizeof(void*) bytes smaller). Each category
end_comment

begin_comment
comment|// of virtual tables is aligned to a different power of 2, precluding the
end_comment

begin_comment
comment|// all-ones optimization. As a result, the bit vector for the base class will
end_comment

begin_comment
comment|// need to contain at least I*2 entries to accommodate all the derived virtual
end_comment

begin_comment
comment|// tables.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|,
name|unsigned
name|I
operator|>
expr|struct
name|Deriver
operator|:
name|T
block|{
name|Deriver
argument_list|()
block|{
name|break_optimization
argument_list|(
argument|new Deriver<T
argument_list|,
argument|I-
literal|1
argument|>
argument_list|)
block|;   }
name|virtual
name|void
name|f
argument_list|()
block|{}
name|virtual
name|void
name|g
argument_list|()
block|{}
name|virtual
name|void
name|h
argument_list|()
block|{}
block|}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|Deriver
operator|<
name|T
operator|,
literal|0
operator|>
operator|:
name|T
block|{
name|virtual
name|void
name|f
argument_list|()
block|{}
name|void
name|g
argument_list|()
block|{}
block|}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|Deriver
operator|<
name|T
operator|,
literal|1
operator|>
operator|:
name|T
block|{
name|Deriver
argument_list|()
block|{
name|break_optimization
argument_list|(
argument|new Deriver<T
argument_list|,
literal|0
argument|>
argument_list|)
block|;   }
name|virtual
name|void
name|f
argument_list|()
block|{}
name|virtual
name|void
name|g
argument_list|()
block|{}
name|virtual
name|void
name|h
argument_list|()
block|{}
name|virtual
name|void
name|i
argument_list|()
block|{}
name|virtual
name|void
name|j
argument_list|()
block|{}
name|virtual
name|void
name|k
argument_list|()
block|{}
name|virtual
name|void
name|l
argument_list|()
block|{}
block|}
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Instantiate enough classes to force CFI checks for type T to use bit
end_comment

begin_comment
comment|// vectors of size 32 (if B32 defined), 64 (if B64 defined) or>64 (if BM
end_comment

begin_comment
comment|// defined).
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|void
name|create_derivers
argument_list|()
block|{
ifdef|#
directive|ifdef
name|B32
name|break_optimization
argument_list|(
argument|new Deriver<T
argument_list|,
literal|10
argument|>
argument_list|)
block|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|B64
name|break_optimization
argument_list|(
argument|new Deriver<T
argument_list|,
literal|25
argument|>
argument_list|)
block|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|BM
name|break_optimization
argument_list|(
argument|new Deriver<T
argument_list|,
literal|40
argument|>
argument_list|)
block|;
endif|#
directive|endif
block|}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

