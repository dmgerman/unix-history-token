begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/* Registered charset names are at most 40 characters long. */
define|#
directive|define
name|CHARSET_MAX
value|41
comment|/* Figure out the charset to use from the ContentType.    buf contains the body of the header field (the part after "Content-Type:").    charset gets the charset to use.  It must be at least CHARSET_MAX chars    long.  charset will be empty if the default charset should be used. */
name|void
name|getXMLCharset
parameter_list|(
specifier|const
name|char
modifier|*
name|buf
parameter_list|,
name|char
modifier|*
name|charset
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

end_unit

