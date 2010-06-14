begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|__RADIOTAP_ITER_H
end_ifndef

begin_define
define|#
directive|define
name|__RADIOTAP_ITER_H
end_define

begin_include
include|#
directive|include
file|"radiotap.h"
end_include

begin_comment
comment|/* Radiotap header iteration  *   implemented in radiotap.c  */
end_comment

begin_comment
comment|/**  * struct ieee80211_radiotap_iterator - tracks walk thru present radiotap args  * @rtheader: pointer to the radiotap header we are walking through  * @max_length: length of radiotap header in cpu byte ordering  * @this_arg_index: IEEE80211_RADIOTAP_... index of current arg  * @this_arg: pointer to current radiotap arg  * @arg_index: internal next argument index  * @arg: internal next argument pointer  * @next_bitmap: internal pointer to next present u32  * @bitmap_shifter: internal shifter for curr u32 bitmap, b0 set == arg present  */
end_comment

begin_struct
struct|struct
name|ieee80211_radiotap_iterator
block|{
name|struct
name|ieee80211_radiotap_header
modifier|*
name|rtheader
decl_stmt|;
name|int
name|max_length
decl_stmt|;
name|int
name|this_arg_index
decl_stmt|;
name|unsigned
name|char
modifier|*
name|this_arg
decl_stmt|;
name|int
name|arg_index
decl_stmt|;
name|unsigned
name|char
modifier|*
name|arg
decl_stmt|;
name|uint32_t
modifier|*
name|next_bitmap
decl_stmt|;
name|uint32_t
name|bitmap_shifter
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|int
name|ieee80211_radiotap_iterator_init
parameter_list|(
name|struct
name|ieee80211_radiotap_iterator
modifier|*
name|iterator
parameter_list|,
name|struct
name|ieee80211_radiotap_header
modifier|*
name|radiotap_header
parameter_list|,
name|int
name|max_length
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ieee80211_radiotap_iterator_next
parameter_list|(
name|struct
name|ieee80211_radiotap_iterator
modifier|*
name|iterator
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __RADIOTAP_ITER_H */
end_comment

end_unit

