begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|emul_init
end_ifndef

begin_define
define|#
directive|define
name|emul_init
value|common_emul_init
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|emul_bfd_name
end_ifndef

begin_define
define|#
directive|define
name|emul_bfd_name
value|default_emul_bfd_name
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|emul_local_labels_fb
end_ifndef

begin_define
define|#
directive|define
name|emul_local_labels_fb
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|emul_local_labels_dollar
end_ifndef

begin_define
define|#
directive|define
name|emul_local_labels_dollar
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|emul_leading_underscore
end_ifndef

begin_define
define|#
directive|define
name|emul_leading_underscore
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|emul_strip_underscore
end_ifndef

begin_define
define|#
directive|define
name|emul_strip_underscore
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|emul_default_endian
end_ifndef

begin_define
define|#
directive|define
name|emul_default_endian
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|emul_fake_label_name
end_ifndef

begin_define
define|#
directive|define
name|emul_fake_label_name
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|struct
name|emulation
name|emul_struct_name
init|=
block|{
literal|0
block|,
name|emul_name
block|,
name|emul_init
block|,
name|emul_bfd_name
block|,
name|emul_local_labels_fb
block|,
name|emul_local_labels_dollar
block|,
name|emul_leading_underscore
block|,
name|emul_strip_underscore
block|,
name|emul_default_endian
block|,
name|emul_fake_label_name
block|,
name|emul_format
block|, }
decl_stmt|;
end_decl_stmt

end_unit

