begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Header: /f/osi/others/quipu/uips/sd/RCS/filt.h,v 7.2 91/02/22 09:32:15 mrose Interim $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FILT
end_ifndef

begin_define
define|#
directive|define
name|FILT
end_define

begin_include
include|#
directive|include
file|"quipu/ds_search.h"
end_include

begin_typedef
typedef|typedef
struct|struct
name|stroid_list
block|{
name|int
name|fi_type
decl_stmt|;
name|char
modifier|*
name|stroid
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
block|}
name|filt_item
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|filter_struct
block|{
name|int
name|flt_type
decl_stmt|;
union|union
name|ftype
block|{
name|filt_item
name|item
decl_stmt|;
name|struct
name|filter_struct
modifier|*
name|sub_filt
decl_stmt|;
block|}
name|fu_cont
union|;
name|struct
name|filter_struct
modifier|*
name|next
decl_stmt|;
block|}
name|filt_struct
typedef|;
end_typedef

begin_function_decl
name|void
name|make_type
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|filt_struct
modifier|*
name|make_item_filter
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|filt_struct
modifier|*
name|link_filters
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|filt_struct
modifier|*
name|make_parent_filter
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|Filter
name|make_filter
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|Filter
name|make_attr_filter
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|free_filt
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

