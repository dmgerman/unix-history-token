begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<X/mit-copyright.h>
end_include

begin_comment
comment|/* $Header: Xkeymap.h,v 10.5 86/02/01 15:41:53 tony Rel $ */
end_comment

begin_comment
comment|/* Copyright 1985, Massachusetts Institute of Technology */
end_comment

begin_define
define|#
directive|define
name|X_KEYMAP_MAGIC
value|0372
end_define

begin_comment
comment|/* magic number which must be first byte     	    	    	    	of a keymap file */
end_comment

begin_comment
comment|/* KeyMap: contains single-byte character bindings, or indications    that a keycode is actually bound in the extension or runtime table */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|char
name|KeyMapElt
index|[
literal|16
index|]
typedef|;
end_typedef

begin_define
define|#
directive|define
name|UNBOUND
value|(unsigned char)'\377'
end_define

begin_define
define|#
directive|define
name|EXTENSION_BOUND
value|(unsigned char)'\376'
end_define

begin_define
define|#
directive|define
name|RUNTIME_TABLE_BOUND
value|(unsigned char)'\375'
end_define

begin_define
define|#
directive|define
name|SingleCharBound
parameter_list|(
name|c
parameter_list|)
value|((unsigned char)c< (unsigned char)'\375')
end_define

begin_comment
comment|/* Extension: contains multiple-byte character bindings from    the keymap file.  Not modified at runtime.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|keycode
decl_stmt|;
name|unsigned
name|char
name|metabits
decl_stmt|;
name|unsigned
name|char
name|length
decl_stmt|;
block|}
name|ExtensionHeader
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ExtensionHeaderSize
value|3
end_define

begin_comment
comment|/* since sizeof (ExtensionHeader) is 4 on some machines, e.g. Sun */
end_comment

begin_comment
comment|/* macro used to iterate through the extension */
end_comment

begin_define
define|#
directive|define
name|NextExtension
parameter_list|(
name|this
parameter_list|)
define|\
value|this = (ExtensionHeader *) ((char *)this + ExtensionHeaderSize + this->length)
end_define

begin_define
define|#
directive|define
name|DontCareMetaBits
value|0377
end_define

begin_comment
comment|/* appears in extension whenever the binding applies to all possible      combinations of shift/lock/meta/control keys */
end_comment

end_unit

