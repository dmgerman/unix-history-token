begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|__IB_INTFC_H__
end_ifndef

begin_define
define|#
directive|define
name|__IB_INTFC_H__
end_define

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_undef
undef|#
directive|undef
name|prefetch
end_undef

begin_undef
undef|#
directive|undef
name|WARN_ON
end_undef

begin_undef
undef|#
directive|undef
name|max_t
end_undef

begin_undef
undef|#
directive|undef
name|udelay
end_undef

begin_undef
undef|#
directive|undef
name|le32_to_cpu
end_undef

begin_undef
undef|#
directive|undef
name|le16_to_cpu
end_undef

begin_undef
undef|#
directive|undef
name|cpu_to_le32
end_undef

begin_undef
undef|#
directive|undef
name|swab32
end_undef

begin_undef
undef|#
directive|undef
name|container_of
end_undef

begin_undef
undef|#
directive|undef
name|LIST_HEAD
end_undef

begin_define
define|#
directive|define
name|LIST_HEAD
parameter_list|(
name|name
parameter_list|,
name|type
parameter_list|)
define|\
value|struct name {                                                           \         struct type *lh_first;
comment|/* first element */
value|\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __IB_INTFC_H__ */
end_comment

end_unit

