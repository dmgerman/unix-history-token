begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * Copyright (c) 1996 Wolfgang Helbig<helbig@ba-stuttgart.de>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Absolutely no warranty of function or purpose is made by the author.  * 4. Modifications may be freely made to this file if the above conditions  *    are met.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|Q_CMD640B
value|0x00000001
end_define

begin_comment
comment|/* CMD640B quirk: serialize IDE channels */
end_comment

begin_function_decl
name|void
name|wdc_pci
parameter_list|(
name|int
name|quirks
parameter_list|)
function_decl|;
end_function_decl

end_unit

