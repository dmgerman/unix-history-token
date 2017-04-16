begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<atomic>
end_include

begin_comment
comment|// Note that although hogging the CPU while waiting for a variable to change
end_comment

begin_comment
comment|// would be terrible in production code, it's great for testing since it
end_comment

begin_comment
comment|// avoids a lot of messy context switching to get multiple threads synchronized.
end_comment

begin_typedef
typedef|typedef
name|std
operator|::
name|atomic
operator|<
name|int
operator|>
name|pseudo_barrier_t
expr_stmt|;
end_typedef

begin_define
define|#
directive|define
name|pseudo_barrier_wait
parameter_list|(
name|barrier
parameter_list|)
define|\
value|do                                      \     {                                       \         --(barrier);                        \         while ((barrier).load()> 0)        \             ;                               \     } while (0)
end_define

begin_define
define|#
directive|define
name|pseudo_barrier_init
parameter_list|(
name|barrier
parameter_list|,
name|count
parameter_list|)
define|\
value|do                                      \     {                                       \         (barrier) = (count);                \     } while (0)
end_define

end_unit

