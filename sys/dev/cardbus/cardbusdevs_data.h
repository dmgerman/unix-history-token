begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*  * THIS FILE AUTOMATICALLY GENERATED.  DO NOT EDIT.  *  * generated from:  *	FreeBSD: src/sys/dev/cardbus/cardbusdevs,v 1.1 1999/11/18 07:21:50 imp Exp   */
end_comment

begin_comment
comment|/*  * Copyright (C) 1999  Hayakawa Koichi.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by the author  *	for the NetBSD Project.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_decl_stmt
name|struct
name|cardbus_knowndev
name|cardbus_knowndevs
index|[]
init|=
block|{
block|{
name|CARDBUS_VENDOR_3COM
block|,
name|CARDBUS_PRODUCT_3COM_3C575TX
block|,
literal|0
block|,
literal|"3Com"
block|,
literal|"3c575 100Base-TX"
block|, 	}
block|,
block|{
name|CARDBUS_VENDOR_3COM
block|,
name|CARDBUS_PRODUCT_3COM_3C575BTX
block|,
literal|0
block|,
literal|"3Com"
block|,
literal|"3c575B 100Base-TX"
block|, 	}
block|,
block|{
name|CARDBUS_VENDOR_ADP
block|,
name|CARDBUS_PRODUCT_ADP_1480
block|,
literal|0
block|,
literal|"Adaptec"
block|,
literal|"APA-1480"
block|, 	}
block|,
block|{
name|CARDBUS_VENDOR_DEC
block|,
name|CARDBUS_PRODUCT_DEC_21142
block|,
literal|0
block|,
literal|"Digital Equipment"
block|,
literal|"DECchip 21142/3"
block|, 	}
block|,
block|{
name|CARDBUS_VENDOR_OPTI
block|,
name|CARDBUS_PRODUCT_OPTI_82C861
block|,
literal|0
block|,
literal|"Opti"
block|,
literal|"82C861 USB Host Controller (OHCI)"
block|, 	}
block|,
block|{
name|CARDBUS_VENDOR_DEC
block|,
literal|0
block|,
name|CARDBUS_KNOWNDEV_NOPROD
block|,
literal|"Digital Equipment"
block|,
name|NULL
block|, 	}
block|,
block|{
name|CARDBUS_VENDOR_3COM
block|,
literal|0
block|,
name|CARDBUS_KNOWNDEV_NOPROD
block|,
literal|"3Com"
block|,
name|NULL
block|, 	}
block|,
block|{
name|CARDBUS_VENDOR_ADP
block|,
literal|0
block|,
name|CARDBUS_KNOWNDEV_NOPROD
block|,
literal|"Adaptec"
block|,
name|NULL
block|, 	}
block|,
block|{
name|CARDBUS_VENDOR_ADP2
block|,
literal|0
block|,
name|CARDBUS_KNOWNDEV_NOPROD
block|,
literal|"Adaptec (2nd PCI Vendor ID)"
block|,
name|NULL
block|, 	}
block|,
block|{
name|CARDBUS_VENDOR_OPTI
block|,
literal|0
block|,
name|CARDBUS_KNOWNDEV_NOPROD
block|,
literal|"Opti"
block|,
name|NULL
block|, 	}
block|,
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
name|NULL
block|,
name|NULL
block|, }
block|}
decl_stmt|;
end_decl_stmt

end_unit

