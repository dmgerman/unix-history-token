begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 Nick Hibma<n_hibma@freebsd.org>  * All rights reserved.  *  * Copyright (c) 2005 Ed Schouten<ed@fxq.nl>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  * This file contains replacements for broken HID report descriptors.  */
end_comment

begin_define
define|#
directive|define
name|UHID_GRAPHIRE_REPORT_DESCR
parameter_list|(
modifier|...
parameter_list|)
define|\
value|0x05, 0x0d,
comment|/*  USAGE_PAGE (Digitizers)		*/
value|\     0x09, 0x01,
comment|/*  USAGE (Digitizer)		*/
value|\     0xa1, 0x01,
comment|/*  COLLECTION (Application)		*/
value|\     0x85, 0x02,
comment|/*    REPORT_ID (2)			*/
value|\     0x05, 0x0d,
comment|/*    USAGE_PAGE (Digitizers)	*/
value|\     0x09, 0x01,
comment|/*    USAGE (Digitizer)		*/
value|\     0xa1, 0x00,
comment|/*    COLLECTION (Physical)		*/
value|\     0x15, 0x00,
comment|/*      LOGICAL_MINIMUM (0)		*/
value|\     0x25, 0x01,
comment|/*      LOGICAL_MAXIMUM (1)		*/
value|\     0x09, 0x33,
comment|/*      USAGE (Touch)		*/
value|\     0x95, 0x01,
comment|/*      REPORT_COUNT (1)		*/
value|\     0x75, 0x01,
comment|/*      REPORT_SIZE (1)		*/
value|\     0x81, 0x02,
comment|/*      INPUT (Data,Var,Abs)		*/
value|\     0x09, 0x44,
comment|/*      USAGE (Barrel Switch)	*/
value|\     0x95, 0x02,
comment|/*      REPORT_COUNT (2)		*/
value|\     0x75, 0x01,
comment|/*      REPORT_SIZE (1)		*/
value|\     0x81, 0x02,
comment|/*      INPUT (Data,Var,Abs)		*/
value|\     0x09, 0x00,
comment|/*      USAGE (Undefined)		*/
value|\     0x95, 0x02,
comment|/*      REPORT_COUNT (2)		*/
value|\     0x75, 0x01,
comment|/*      REPORT_SIZE (1)		*/
value|\     0x81, 0x03,
comment|/*      INPUT (Cnst,Var,Abs)		*/
value|\     0x09, 0x3c,
comment|/*      USAGE (Invert)		*/
value|\     0x95, 0x01,
comment|/*      REPORT_COUNT (1)		*/
value|\     0x75, 0x01,
comment|/*      REPORT_SIZE (1)		*/
value|\     0x81, 0x02,
comment|/*      INPUT (Data,Var,Abs)		*/
value|\     0x09, 0x38,
comment|/*      USAGE (Transducer Index)	*/
value|\     0x95, 0x01,
comment|/*      REPORT_COUNT (1)		*/
value|\     0x75, 0x01,
comment|/*      REPORT_SIZE (1)		*/
value|\     0x81, 0x02,
comment|/*      INPUT (Data,Var,Abs)		*/
value|\     0x09, 0x32,
comment|/*      USAGE (In Range)		*/
value|\     0x95, 0x01,
comment|/*      REPORT_COUNT (1)		*/
value|\     0x75, 0x01,
comment|/*      REPORT_SIZE (1)		*/
value|\     0x81, 0x02,
comment|/*      INPUT (Data,Var,Abs)		*/
value|\     0x05, 0x01,
comment|/*      USAGE_PAGE (Generic Desktop)	*/
value|\     0x09, 0x30,
comment|/*      USAGE (X)			*/
value|\     0x15, 0x00,
comment|/*      LOGICAL_MINIMUM (0)		*/
value|\     0x26, 0xde, 0x27,
comment|/*      LOGICAL_MAXIMUM (10206)	*/
value|\     0x95, 0x01,
comment|/*      REPORT_COUNT (1)		*/
value|\     0x75, 0x10,
comment|/*      REPORT_SIZE (16)		*/
value|\     0x81, 0x02,
comment|/*      INPUT (Data,Var,Abs)		*/
value|\     0x09, 0x31,
comment|/*      USAGE (Y)			*/
value|\     0x26, 0xfe, 0x1c,
comment|/*      LOGICAL_MAXIMUM (7422)	*/
value|\     0x95, 0x01,
comment|/*      REPORT_COUNT (1)		*/
value|\     0x75, 0x10,
comment|/*      REPORT_SIZE (16)		*/
value|\     0x81, 0x02,
comment|/*      INPUT (Data,Var,Abs)		*/
value|\     0x05, 0x0d,
comment|/*      USAGE_PAGE (Digitizers)	*/
value|\     0x09, 0x30,
comment|/*      USAGE (Tip Pressure)		*/
value|\     0x26, 0xff, 0x01,
comment|/*      LOGICAL_MAXIMUM (511)	*/
value|\     0x95, 0x01,
comment|/*      REPORT_COUNT (1)		*/
value|\     0x75, 0x10,
comment|/*      REPORT_SIZE (16)		*/
value|\     0x81, 0x02,
comment|/*      INPUT (Data,Var,Abs)		*/
value|\     0xc0,
comment|/*    END_COLLECTION			*/
value|\     0x05, 0x0d,
comment|/*    USAGE_PAGE (Digitizers)	*/
value|\     0x09, 0x00,
comment|/*    USAGE (Undefined)		*/
value|\     0x85, 0x02,
comment|/*    REPORT_ID (2)			*/
value|\     0x95, 0x01,
comment|/*    REPORT_COUNT (1)		*/
value|\     0xb1, 0x02,
comment|/*    FEATURE (Data,Var,Abs)		*/
value|\     0x09, 0x00,
comment|/*    USAGE (Undefined)		*/
value|\     0x85, 0x03,
comment|/*    REPORT_ID (3)			*/
value|\     0x95, 0x01,
comment|/*    REPORT_COUNT (1)		*/
value|\     0xb1, 0x02,
comment|/*    FEATURE (Data,Var,Abs)		*/
value|\     0xc0,
comment|/*  END_COLLECTION			*/
value|\  #define	UHID_GRAPHIRE3_4X5_REPORT_DESCR(...) \     0x05, 0x01,
comment|/* USAGE_PAGE (Generic Desktop)	*/
value|\     0x09, 0x02,
comment|/* USAGE (Mouse)			*/
value|\     0xa1, 0x01,
comment|/* COLLECTION (Application)		*/
value|\     0x85, 0x01,
comment|/*   REPORT_ID (1)			*/
value|\     0x09, 0x01,
comment|/*   USAGE (Pointer)			*/
value|\     0xa1, 0x00,
comment|/*   COLLECTION (Physical)		*/
value|\     0x05, 0x09,
comment|/*     USAGE_PAGE (Button)		*/
value|\     0x19, 0x01,
comment|/*     USAGE_MINIMUM (Button 1)	*/
value|\     0x29, 0x03,
comment|/*     USAGE_MAXIMUM (Button 3)	*/
value|\     0x15, 0x00,
comment|/*     LOGICAL_MINIMUM (0)		*/
value|\     0x25, 0x01,
comment|/*     LOGICAL_MAXIMUM (1)		*/
value|\     0x95, 0x03,
comment|/*     REPORT_COUNT (3)		*/
value|\     0x75, 0x01,
comment|/*     REPORT_SIZE (1)		*/
value|\     0x81, 0x02,
comment|/*     INPUT (Data,Var,Abs)		*/
value|\     0x95, 0x01,
comment|/*     REPORT_COUNT (1)		*/
value|\     0x75, 0x05,
comment|/*     REPORT_SIZE (5)		*/
value|\     0x81, 0x01,
comment|/*     INPUT (Cnst,Ary,Abs)		*/
value|\     0x05, 0x01,
comment|/*     USAGE_PAGE (Generic Desktop)	*/
value|\     0x09, 0x30,
comment|/*     USAGE (X)			*/
value|\     0x09, 0x31,
comment|/*     USAGE (Y)			*/
value|\     0x09, 0x38,
comment|/*     USAGE (Wheel)			*/
value|\     0x15, 0x81,
comment|/*     LOGICAL_MINIMUM (-127)	*/
value|\     0x25, 0x7f,
comment|/*     LOGICAL_MAXIMUM (127)		*/
value|\     0x75, 0x08,
comment|/*     REPORT_SIZE (8)		*/
value|\     0x95, 0x03,
comment|/*     REPORT_COUNT (3)		*/
value|\     0x81, 0x06,
comment|/*     INPUT (Data,Var,Rel)		*/
value|\     0xc0,
comment|/*   END_COLLECTION			*/
value|\     0xc0,
comment|/* END_COLLECTION			*/
value|\     0x05, 0x0d,
comment|/* USAGE_PAGE (Digitizers)		*/
value|\     0x09, 0x01,
comment|/* USAGE (Pointer)			*/
value|\     0xa1, 0x01,
comment|/* COLLECTION (Applicaption)		*/
value|\     0x85, 0x02,
comment|/*   REPORT_ID (2)			*/
value|\     0x05, 0x0d,
comment|/*   USAGE_PAGE (Digitizers)		*/
value|\     0x09, 0x01,
comment|/*   USAGE (Digitizer)		*/
value|\     0xa1, 0x00,
comment|/*   COLLECTION (Physical)		*/
value|\     0x09, 0x33,
comment|/*     USAGE (Touch)			*/
value|\     0x09, 0x44,
comment|/*     USAGE (Barrel Switch)		*/
value|\     0x09, 0x44,
comment|/*     USAGE (Barrel Switch)		*/
value|\     0x15, 0x00,
comment|/*     LOGICAL_MINIMUM (0)		*/
value|\     0x25, 0x01,
comment|/*     LOGICAL_MAXIMUM (1)		*/
value|\     0x75, 0x01,
comment|/*     REPORT_SIZE (1)		*/
value|\     0x95, 0x03,
comment|/*     REPORT_COUNT (3)		*/
value|\     0x81, 0x02,
comment|/*     INPUT (Data,Var,Abs)		*/
value|\     0x75, 0x01,
comment|/*     REPORT_SIZE (1)		*/
value|\     0x95, 0x02,
comment|/*     REPORT_COUNT (2)		*/
value|\     0x81, 0x01,
comment|/*     INPUT (Cnst,Ary,Abs)		*/
value|\     0x09, 0x3c,
comment|/*     USAGE (Invert)		*/
value|\     0x09, 0x38,
comment|/*     USAGE (Transducer Index)	*/
value|\     0x09, 0x32,
comment|/*     USAGE (In Range)		*/
value|\     0x75, 0x01,
comment|/*     REPORT_SIZE (1)		*/
value|\     0x95, 0x03,
comment|/*     REPORT_COUNT (3)		*/
value|\     0x81, 0x02,
comment|/*     INPUT (Data,Var,Abs)		*/
value|\     0x05, 0x01,
comment|/*     USAGE_PAGE (Generic Desktop)	*/
value|\     0x09, 0x30,
comment|/*     USAGE (X)			*/
value|\     0x15, 0x00,
comment|/*     LOGICAL_MINIMUM (0)		*/
value|\     0x26, 0xde, 0x27,
comment|/*     LOGICAL_MAXIMUM (10206)	*/
value|\     0x75, 0x10,
comment|/*     REPORT_SIZE (16)		*/
value|\     0x95, 0x01,
comment|/*     REPORT_COUNT (1)		*/
value|\     0x81, 0x02,
comment|/*     INPUT (Data,Var,Abs)		*/
value|\     0x09, 0x31,
comment|/*     USAGE (Y)			*/
value|\     0x26, 0xfe, 0x1c,
comment|/*     LOGICAL_MAXIMUM (7422)	*/
value|\     0x75, 0x10,
comment|/*     REPORT_SIZE (16)		*/
value|\     0x95, 0x01,
comment|/*     REPORT_COUNT (1)		*/
value|\     0x81, 0x02,
comment|/*     INPUT (Data,Var,Abs)		*/
value|\     0x05, 0x0d,
comment|/*     USAGE_PAGE (Digitizers)	*/
value|\     0x09, 0x30,
comment|/*     USAGE (Tip Pressure)		*/
value|\     0x26, 0xff, 0x01,
comment|/*     LOGICAL_MAXIMUM (511)		*/
value|\     0x75, 0x10,
comment|/*     REPORT_SIZE (16)		*/
value|\     0x95, 0x01,
comment|/*     REPORT_COUNT (1)		*/
value|\     0x81, 0x02,
comment|/*     INPUT (Data,Var,Abs)		*/
value|\     0xc0,
comment|/*   END_COLLECTION			*/
value|\     0x05, 0x0d,
comment|/*   USAGE_PAGE (Digitizers)		*/
value|\     0x09, 0x00,
comment|/*   USAGE (Undefined)		*/
value|\     0x85, 0x02,
comment|/*   REPORT_ID (2)			*/
value|\     0x95, 0x01,
comment|/*   REPORT_COUNT (1)		*/
value|\     0xb1, 0x02,
comment|/*   FEATURE (Data,Var,Abs)		*/
value|\     0x09, 0x00,
comment|/*   USAGE (Undefined)		*/
value|\     0x85, 0x03,
comment|/*   REPORT_ID (3)			*/
value|\     0x95, 0x01,
comment|/*   REPORT_COUNT (1)		*/
value|\     0xb1, 0x02,
comment|/*   FEATURE (Data,Var,Abs)		*/
value|\     0xc0
end_define

begin_comment
comment|/* END_COLLECTION			*/
end_comment

begin_comment
unit|\
comment|/*  * The descriptor has no output report format, thus preventing you from  * controlling the LEDs and the built-in rumblers.  */
end_comment

begin_define
define|#
directive|define
name|UHID_XB360GP_REPORT_DESCR
parameter_list|(
modifier|...
parameter_list|)
define|\
value|0x05, 0x01,
comment|/* USAGE PAGE (Generic Desktop)		*/
value|\     0x09, 0x05,
comment|/* USAGE (Gamepad)			*/
value|\     0xa1, 0x01,
comment|/* COLLECTION (Application)		*/
value|\
comment|/* Unused */
value|\     0x75, 0x08,
comment|/*  REPORT SIZE (8)			*/
value|\     0x95, 0x01,
comment|/*  REPORT COUNT (1)			*/
value|\     0x81, 0x01,
comment|/*  INPUT (Constant)			*/
value|\
comment|/* Byte count */
value|\     0x75, 0x08,
comment|/*  REPORT SIZE (8)			*/
value|\     0x95, 0x01,
comment|/*  REPORT COUNT (1)			*/
value|\     0x05, 0x01,
comment|/*  USAGE PAGE (Generic Desktop)	*/
value|\     0x09, 0x3b,
comment|/*  USAGE (Byte Count)			*/
value|\     0x81, 0x01,
comment|/*  INPUT (Constant)			*/
value|\
comment|/* D-Pad */
value|\     0x05, 0x01,
comment|/*  USAGE PAGE (Generic Desktop)	*/
value|\     0x09, 0x01,
comment|/*  USAGE (Pointer)			*/
value|\     0xa1, 0x00,
comment|/*  COLLECTION (Physical)		*/
value|\     0x75, 0x01,
comment|/*   REPORT SIZE (1)			*/
value|\     0x15, 0x00,
comment|/*   LOGICAL MINIMUM (0)		*/
value|\     0x25, 0x01,
comment|/*   LOGICAL MAXIMUM (1)		*/
value|\     0x35, 0x00,
comment|/*   PHYSICAL MINIMUM (0)		*/
value|\     0x45, 0x01,
comment|/*   PHYSICAL MAXIMUM (1)		*/
value|\     0x95, 0x04,
comment|/*   REPORT COUNT (4)			*/
value|\     0x05, 0x01,
comment|/*   USAGE PAGE (Generic Desktop)	*/
value|\     0x09, 0x90,
comment|/*   USAGE (D-Pad Up)			*/
value|\     0x09, 0x91,
comment|/*   USAGE (D-Pad Down)			*/
value|\     0x09, 0x93,
comment|/*   USAGE (D-Pad Left)			*/
value|\     0x09, 0x92,
comment|/*   USAGE (D-Pad Right)		*/
value|\     0x81, 0x02,
comment|/*   INPUT (Data, Variable, Absolute)	*/
value|\     0xc0,
comment|/*  END COLLECTION			*/
value|\
comment|/* Buttons 5-11 */
value|\     0x75, 0x01,
comment|/*  REPORT SIZE (1)			*/
value|\     0x15, 0x00,
comment|/*  LOGICAL MINIMUM (0)			*/
value|\     0x25, 0x01,
comment|/*  LOGICAL MAXIMUM (1)			*/
value|\     0x35, 0x00,
comment|/*  PHYSICAL MINIMUM (0)		*/
value|\     0x45, 0x01,
comment|/*  PHYSICAL MAXIMUM (1)		*/
value|\     0x95, 0x07,
comment|/*  REPORT COUNT (7)			*/
value|\     0x05, 0x09,
comment|/*  USAGE PAGE (Button)			*/
value|\     0x09, 0x08,
comment|/*  USAGE (Button 8)			*/
value|\     0x09, 0x07,
comment|/*  USAGE (Button 7)			*/
value|\     0x09, 0x09,
comment|/*  USAGE (Button 9)			*/
value|\     0x09, 0x0a,
comment|/*  USAGE (Button 10)			*/
value|\     0x09, 0x05,
comment|/*  USAGE (Button 5)			*/
value|\     0x09, 0x06,
comment|/*  USAGE (Button 6)			*/
value|\     0x09, 0x0b,
comment|/*  USAGE (Button 11)			*/
value|\     0x81, 0x02,
comment|/*  INPUT (Data, Variable, Absolute)	*/
value|\
comment|/* Unused */
value|\     0x75, 0x01,
comment|/*  REPORT SIZE (1)			*/
value|\     0x95, 0x01,
comment|/*  REPORT COUNT (1)			*/
value|\     0x81, 0x01,
comment|/*  INPUT (Constant)			*/
value|\
comment|/* Buttons 1-4 */
value|\     0x75, 0x01,
comment|/*  REPORT SIZE (1)			*/
value|\     0x15, 0x00,
comment|/*  LOGICAL MINIMUM (0)			*/
value|\     0x25, 0x01,
comment|/*  LOGICAL MAXIMUM (1)			*/
value|\     0x35, 0x00,
comment|/*  PHYSICAL MINIMUM (0)		*/
value|\     0x45, 0x01,
comment|/*  PHYSICAL MAXIMUM (1)		*/
value|\     0x95, 0x04,
comment|/*  REPORT COUNT (4)			*/
value|\     0x05, 0x09,
comment|/*  USAGE PAGE (Button)			*/
value|\     0x19, 0x01,
comment|/*  USAGE MINIMUM (Button 1)		*/
value|\     0x29, 0x04,
comment|/*  USAGE MAXIMUM (Button 4)		*/
value|\     0x81, 0x02,
comment|/*  INPUT (Data, Variable, Absolute)	*/
value|\
comment|/* Triggers */
value|\     0x75, 0x08,
comment|/*  REPORT SIZE (8)			*/
value|\     0x15, 0x00,
comment|/*  LOGICAL MINIMUM (0)			*/
value|\     0x26, 0xff, 0x00,
comment|/*  LOGICAL MAXIMUM (255)		*/
value|\     0x35, 0x00,
comment|/*  PHYSICAL MINIMUM (0)		*/
value|\     0x46, 0xff, 0x00,
comment|/*  PHYSICAL MAXIMUM (255)		*/
value|\     0x95, 0x02,
comment|/*  REPORT SIZE (2)			*/
value|\     0x05, 0x01,
comment|/*  USAGE PAGE (Generic Desktop)	*/
value|\     0x09, 0x32,
comment|/*  USAGE (Z)				*/
value|\     0x09, 0x35,
comment|/*  USAGE (Rz)				*/
value|\     0x81, 0x02,
comment|/*  INPUT (Data, Variable, Absolute)	*/
value|\
comment|/* Sticks */
value|\     0x75, 0x10,
comment|/*  REPORT SIZE (16)			*/
value|\     0x16, 0x00, 0x80,
comment|/*  LOGICAL MINIMUM (-32768)		*/
value|\     0x26, 0xff, 0x7f,
comment|/*  LOGICAL MAXIMUM (32767)		*/
value|\     0x36, 0x00, 0x80,
comment|/*  PHYSICAL MINIMUM (-32768)		*/
value|\     0x46, 0xff, 0x7f,
comment|/*  PHYSICAL MAXIMUM (32767)		*/
value|\     0x95, 0x04,
comment|/*  REPORT COUNT (4)			*/
value|\     0x05, 0x01,
comment|/*  USAGE PAGE (Generic Desktop)	*/
value|\     0x09, 0x30,
comment|/*  USAGE (X)				*/
value|\     0x09, 0x31,
comment|/*  USAGE (Y)				*/
value|\     0x09, 0x33,
comment|/*  USAGE (Rx)				*/
value|\     0x09, 0x34,
comment|/*  USAGE (Ry)				*/
value|\     0x81, 0x02,
comment|/*  INPUT (Data, Variable, Absolute)	*/
value|\
comment|/* Unused */
value|\     0x75, 0x30,
comment|/*  REPORT SIZE (48)			*/
value|\     0x95, 0x01,
comment|/*  REPORT COUNT (1)			*/
value|\     0x81, 0x01,
comment|/*  INPUT (Constant)			*/
value|\     0xc0
end_define

begin_comment
comment|/* END COLLECTION			*/
end_comment

unit|\
end_unit

