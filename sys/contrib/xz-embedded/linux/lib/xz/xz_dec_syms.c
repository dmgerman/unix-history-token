begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * XZ decoder module information  *  * Author: Lasse Collin<lasse.collin@tukaani.org>  *  * This file has been put into the public domain.  * You can do whatever you want with this file.  */
end_comment

begin_include
include|#
directive|include
file|<linux/module.h>
end_include

begin_include
include|#
directive|include
file|<linux/xz.h>
end_include

begin_expr_stmt
name|EXPORT_SYMBOL
argument_list|(
name|xz_dec_init
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|EXPORT_SYMBOL
argument_list|(
name|xz_dec_reset
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|EXPORT_SYMBOL
argument_list|(
name|xz_dec_run
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|EXPORT_SYMBOL
argument_list|(
name|xz_dec_end
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MODULE_DESCRIPTION
argument_list|(
literal|"XZ decompressor"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MODULE_VERSION
argument_list|(
literal|"1.0"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MODULE_AUTHOR
argument_list|(
literal|"Lasse Collin<lasse.collin@tukaani.org> and Igor Pavlov"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * This code is in the public domain, but in Linux it's simplest to just  * say it's GPL and consider the authors as the copyright holders.  */
end_comment

begin_expr_stmt
name|MODULE_LICENSE
argument_list|(
literal|"GPL"
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

