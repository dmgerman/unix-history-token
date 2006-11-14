begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* crypt.h (dummy version) -- do not perform encryption  * Hardly worth copyrighting :-)  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CRYPT
end_ifdef

begin_undef
undef|#
directive|undef
name|CRYPT
end_undef

begin_comment
comment|/* dummy version */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|RAND_HEAD_LEN
value|12
end_define

begin_comment
comment|/* length of encryption random header */
end_comment

begin_define
define|#
directive|define
name|zencode
end_define

begin_define
define|#
directive|define
name|zdecode
end_define

end_unit

