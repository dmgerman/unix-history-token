begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	in_systm.h	6.1	83/07/29	*/
end_comment

begin_comment
comment|/*  * Miscellaneous internetwork  * definitions for kernel.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_comment
comment|/*  * Network types.  *  * Internally the system keeps counters in the headers with the bytes  * swapped so that VAX instructions will work on them.  It reverses  * the bytes before transmission at each protocol level.  The n_ types  * represent the types with the bytes in ``high-ender'' order.  */
end_comment

begin_typedef
typedef|typedef
name|u_short
name|n_short
typedef|;
end_typedef

begin_comment
comment|/* short as received from the net */
end_comment

begin_typedef
typedef|typedef
name|u_long
name|n_long
typedef|;
end_typedef

begin_comment
comment|/* long as received from the net */
end_comment

begin_typedef
typedef|typedef
name|u_long
name|n_time
typedef|;
end_typedef

begin_comment
comment|/* ms since 00:00 GMT, byte rev */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_function_decl
name|n_time
name|iptime
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

