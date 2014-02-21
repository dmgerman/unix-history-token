begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|VERSION_H
end_ifndef

begin_define
define|#
directive|define
name|VERSION_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|VERSION_STR_POSTFIX
end_ifndef

begin_define
define|#
directive|define
name|VERSION_STR_POSTFIX
value|""
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VERSION_STR_POSTFIX */
end_comment

begin_define
define|#
directive|define
name|VERSION_STR
value|"2.0" VERSION_STR_POSTFIX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VERSION_H */
end_comment

end_unit

