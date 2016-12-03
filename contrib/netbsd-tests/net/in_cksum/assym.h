begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* XXX: Depends on m_hdr */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_LP64
end_ifdef

begin_define
define|#
directive|define
name|M_NEXT
value|0
end_define

begin_define
define|#
directive|define
name|M_DATA
value|16
end_define

begin_define
define|#
directive|define
name|M_LEN
value|32
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|M_NEXT
value|0
end_define

begin_define
define|#
directive|define
name|M_DATA
value|8
end_define

begin_define
define|#
directive|define
name|M_LEN
value|16
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

