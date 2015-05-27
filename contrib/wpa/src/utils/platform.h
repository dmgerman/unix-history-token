begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|PLATFORM_H
end_ifndef

begin_define
define|#
directive|define
name|PLATFORM_H
end_define

begin_include
include|#
directive|include
file|"includes.h"
end_include

begin_include
include|#
directive|include
file|"common.h"
end_include

begin_define
define|#
directive|define
name|le16_to_cpu
value|le_to_host16
end_define

begin_define
define|#
directive|define
name|le32_to_cpu
value|le_to_host32
end_define

begin_define
define|#
directive|define
name|get_unaligned
parameter_list|(
name|p
parameter_list|)
define|\
value|({								\ 	struct packed_dummy_struct {				\ 		typeof(*(p)) __val;				\ 	} __attribute__((packed)) *__ptr = (void *) (p);	\ 								\ 	__ptr->__val;						\ })
end_define

begin_define
define|#
directive|define
name|get_unaligned_le16
parameter_list|(
name|p
parameter_list|)
value|le16_to_cpu(get_unaligned((uint16_t *)(p)))
end_define

begin_define
define|#
directive|define
name|get_unaligned_le32
parameter_list|(
name|p
parameter_list|)
value|le32_to_cpu(get_unaligned((uint32_t *)(p)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PLATFORM_H */
end_comment

end_unit

