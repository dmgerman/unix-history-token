begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: usbdevs_data.h,v 1.6 1998/10/05 02:31:14 mark Exp $	*/
end_comment

begin_comment
comment|/*  * THIS FILE AUTOMATICALLY GENERATED.  DO NOT EDIT.  *  * generated from:  *	NetBSD: usbdevs,v 1.5 1998/10/05 02:30:17 mark Exp   */
end_comment

begin_comment
comment|/*  * Copyright (c) 1998 The NetBSD Foundation, Inc.  * All rights reserved.  *  * Author: Lennart Augustsson<augustss@carlstedt.se>  *         Carlstedt Research& Technology  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_decl_stmt
name|struct
name|usb_knowndev
name|usb_knowndevs
index|[]
init|=
block|{
block|{
name|USB_VENDOR_NEC
block|,
name|USB_PRODUCT_NEC_HUB
block|,
literal|0
block|,
literal|"NEC"
block|,
literal|"hub"
block|, 	}
block|,
block|{
name|USB_VENDOR_KODAK
block|,
name|USB_PRODUCT_KODAK_DC260
block|,
literal|0
block|,
literal|"Eastman Kodak"
block|,
literal|"Digital Science DC260"
block|, 	}
block|,
block|{
name|USB_VENDOR_NANAO
block|,
name|USB_PRODUCT_NANAO_HUB
block|,
literal|0
block|,
literal|"Nanao"
block|,
literal|"hub"
block|, 	}
block|,
block|{
name|USB_VENDOR_NANAO
block|,
name|USB_PRODUCT_NANAO_MONITOR
block|,
literal|0
block|,
literal|"Nanao"
block|,
literal|"monitor"
block|, 	}
block|,
block|{
name|USB_VENDOR_UNIXTAR
block|,
name|USB_PRODUCT_UNIXTAR_UTUSB41
block|,
literal|0
block|,
literal|"Unixtar"
block|,
literal|"UT-USB41"
block|, 	}
block|,
block|{
name|USB_VENDOR_GENIUS
block|,
name|USB_PRODUCT_GENIUS_NICHE
block|,
literal|0
block|,
literal|"Genius"
block|,
literal|"Niche mouse"
block|, 	}
block|,
block|{
name|USB_VENDOR_GENIUS
block|,
name|USB_PRODUCT_GENIUS_FLIGHT2000
block|,
literal|0
block|,
literal|"Genius"
block|,
literal|"Flight 2000 joystick"
block|, 	}
block|,
block|{
name|USB_VENDOR_CHERRY
block|,
name|USB_PRODUCT_CHERRY_MY3000KBD
block|,
literal|0
block|,
literal|"Cherry"
block|,
literal|"My3000 keyboard"
block|, 	}
block|,
block|{
name|USB_VENDOR_CHERRY
block|,
name|USB_PRODUCT_CHERRY_MY3000HUB
block|,
literal|0
block|,
literal|"Cherry"
block|,
literal|"My3000 hub"
block|, 	}
block|,
block|{
name|USB_VENDOR_PHILIPS
block|,
name|USB_PRODUCT_PHILIPS_DSS
block|,
literal|0
block|,
literal|"Philips"
block|,
literal|"DSS 350 Digital Speaker System"
block|, 	}
block|,
block|{
name|USB_VENDOR_PHILIPS
block|,
name|USB_PRODUCT_PHILIPS_HUB
block|,
literal|0
block|,
literal|"Philips"
block|,
literal|"hub"
block|, 	}
block|,
block|{
name|USB_VENDOR_CONNECTIX
block|,
name|USB_PRODUCT_CONNECTIX_QUICKCAM
block|,
literal|0
block|,
literal|"Connectix"
block|,
literal|"QuickCam"
block|, 	}
block|,
block|{
name|USB_VENDOR_CYPRESS
block|,
name|USB_PRODUCT_CYPRESS_MOUSE
block|,
literal|0
block|,
literal|"Cypress Semicondutor"
block|,
literal|"mouse"
block|, 	}
block|,
block|{
name|USB_VENDOR_BELKIN
block|,
name|USB_PRODUCT_BELKIN_F5U002
block|,
literal|0
block|,
literal|"Belkin"
block|,
literal|"Parallel printer adapter"
block|, 	}
block|,
block|{
name|USB_VENDOR_EIZO
block|,
name|USB_PRODUCT_EIZO_HUB
block|,
literal|0
block|,
literal|"EIZO"
block|,
literal|"hub"
block|, 	}
block|,
block|{
name|USB_VENDOR_EIZO
block|,
name|USB_PRODUCT_EIZO_MONITOR
block|,
literal|0
block|,
literal|"EIZO"
block|,
literal|"monitor"
block|, 	}
block|,
block|{
name|USB_VENDOR_EIZONANAO
block|,
name|USB_PRODUCT_EIZONANAO_HUB
block|,
literal|0
block|,
literal|"EIZO Nanao"
block|,
literal|"hub"
block|, 	}
block|,
block|{
name|USB_VENDOR_EIZONANAO
block|,
name|USB_PRODUCT_EIZONANAO_MONITOR
block|,
literal|0
block|,
literal|"EIZO Nanao"
block|,
literal|"monitor"
block|, 	}
block|,
block|{
name|USB_VENDOR_CHIC
block|,
name|USB_PRODUCT_CHIC_MOUSE1
block|,
literal|0
block|,
literal|"Chic Technology"
block|,
literal|"mouse"
block|, 	}
block|,
block|{
name|USB_VENDOR_PLX
block|,
name|USB_PRODUCT_PLX_TESTBOARD
block|,
literal|0
block|,
literal|"PLX"
block|,
literal|"test board"
block|, 	}
block|,
block|{
name|USB_VENDOR_INSIDEOUT
block|,
name|USB_PRODUCT_INSIDEOUT_EDGEPORT4
block|,
literal|0
block|,
literal|"Inside Out Networks"
block|,
literal|"EdgePort/4"
block|, 	}
block|,
block|{
name|USB_VENDOR_INTEL
block|,
name|USB_PRODUCT_INTEL_TESTBOARD
block|,
literal|0
block|,
literal|"Intel"
block|,
literal|"82930 test board"
block|, 	}
block|,
block|{
name|USB_VENDOR_NEC
block|,
literal|0
block|,
name|USB_KNOWNDEV_NOPROD
block|,
literal|"NEC"
block|,
name|NULL
block|, 	}
block|,
block|{
name|USB_VENDOR_KODAK
block|,
literal|0
block|,
name|USB_KNOWNDEV_NOPROD
block|,
literal|"Eastman Kodak"
block|,
name|NULL
block|, 	}
block|,
block|{
name|USB_VENDOR_NANAO
block|,
literal|0
block|,
name|USB_KNOWNDEV_NOPROD
block|,
literal|"Nanao"
block|,
name|NULL
block|, 	}
block|,
block|{
name|USB_VENDOR_UNIXTAR
block|,
literal|0
block|,
name|USB_KNOWNDEV_NOPROD
block|,
literal|"Unixtar"
block|,
name|NULL
block|, 	}
block|,
block|{
name|USB_VENDOR_GENIUS
block|,
literal|0
block|,
name|USB_KNOWNDEV_NOPROD
block|,
literal|"Genius"
block|,
name|NULL
block|, 	}
block|,
block|{
name|USB_VENDOR_CHERRY
block|,
literal|0
block|,
name|USB_KNOWNDEV_NOPROD
block|,
literal|"Cherry"
block|,
name|NULL
block|, 	}
block|,
block|{
name|USB_VENDOR_PHILIPS
block|,
literal|0
block|,
name|USB_KNOWNDEV_NOPROD
block|,
literal|"Philips"
block|,
name|NULL
block|, 	}
block|,
block|{
name|USB_VENDOR_CONNECTIX
block|,
literal|0
block|,
name|USB_KNOWNDEV_NOPROD
block|,
literal|"Connectix"
block|,
name|NULL
block|, 	}
block|,
block|{
name|USB_VENDOR_CYPRESS
block|,
literal|0
block|,
name|USB_KNOWNDEV_NOPROD
block|,
literal|"Cypress Semicondutor"
block|,
name|NULL
block|, 	}
block|,
block|{
name|USB_VENDOR_EIZO
block|,
literal|0
block|,
name|USB_KNOWNDEV_NOPROD
block|,
literal|"EIZO"
block|,
name|NULL
block|, 	}
block|,
block|{
name|USB_VENDOR_BELKIN
block|,
literal|0
block|,
name|USB_KNOWNDEV_NOPROD
block|,
literal|"Belkin"
block|,
name|NULL
block|, 	}
block|,
block|{
name|USB_VENDOR_EIZONANAO
block|,
literal|0
block|,
name|USB_KNOWNDEV_NOPROD
block|,
literal|"EIZO Nanao"
block|,
name|NULL
block|, 	}
block|,
block|{
name|USB_VENDOR_CHIC
block|,
literal|0
block|,
name|USB_KNOWNDEV_NOPROD
block|,
literal|"Chic Technology"
block|,
name|NULL
block|, 	}
block|,
block|{
name|USB_VENDOR_PLX
block|,
literal|0
block|,
name|USB_KNOWNDEV_NOPROD
block|,
literal|"PLX"
block|,
name|NULL
block|, 	}
block|,
block|{
name|USB_VENDOR_INSIDEOUT
block|,
literal|0
block|,
name|USB_KNOWNDEV_NOPROD
block|,
literal|"Inside Out Networks"
block|,
name|NULL
block|, 	}
block|,
block|{
name|USB_VENDOR_INTEL
block|,
literal|0
block|,
name|USB_KNOWNDEV_NOPROD
block|,
literal|"Intel"
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

