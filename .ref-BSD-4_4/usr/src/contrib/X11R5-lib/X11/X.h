begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	$XConsortium: X.h,v 1.66 88/09/06 15:55:56 jim Exp $  */
end_comment

begin_comment
comment|/* Definitions for the X window system likely to be used by applications */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|X_H
end_ifndef

begin_define
define|#
directive|define
name|X_H
end_define

begin_comment
comment|/*********************************************************** Copyright 1987 by Digital Equipment Corporation, Maynard, Massachusetts, and the Massachusetts Institute of Technology, Cambridge, Massachusetts.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the names of Digital or MIT not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_define
define|#
directive|define
name|X_PROTOCOL
value|11
end_define

begin_comment
comment|/* current protocol version */
end_comment

begin_define
define|#
directive|define
name|X_PROTOCOL_REVISION
value|0
end_define

begin_comment
comment|/* current minor version */
end_comment

begin_comment
comment|/* Resources */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|XID
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|XID
name|Window
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|XID
name|Drawable
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|XID
name|Font
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|XID
name|Pixmap
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|XID
name|Cursor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|XID
name|Colormap
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|XID
name|GContext
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|XID
name|KeySym
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|Mask
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|Atom
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|VisualID
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|Time
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|KeyCode
typedef|;
end_typedef

begin_comment
comment|/*****************************************************************  * RESERVED RESOURCE AND CONSTANT DEFINITIONS  *****************************************************************/
end_comment

begin_define
define|#
directive|define
name|None
value|0L
end_define

begin_comment
comment|/* universal null resource or null atom */
end_comment

begin_define
define|#
directive|define
name|ParentRelative
value|1L
end_define

begin_comment
comment|/* background pixmap in CreateWindow 				    and ChangeWindowAttributes */
end_comment

begin_define
define|#
directive|define
name|CopyFromParent
value|0L
end_define

begin_comment
comment|/* border pixmap in CreateWindow 				       and ChangeWindowAttributes 				   special VisualID and special window 				       class passed to CreateWindow */
end_comment

begin_define
define|#
directive|define
name|PointerWindow
value|0L
end_define

begin_comment
comment|/* destination window in SendEvent */
end_comment

begin_define
define|#
directive|define
name|InputFocus
value|1L
end_define

begin_comment
comment|/* destination window in SendEvent */
end_comment

begin_define
define|#
directive|define
name|PointerRoot
value|1L
end_define

begin_comment
comment|/* focus window in SetInputFocus */
end_comment

begin_define
define|#
directive|define
name|AnyPropertyType
value|0L
end_define

begin_comment
comment|/* special Atom, passed to GetProperty */
end_comment

begin_define
define|#
directive|define
name|AnyKey
value|0L
end_define

begin_comment
comment|/* special Key Code, passed to GrabKey */
end_comment

begin_define
define|#
directive|define
name|AnyButton
value|0L
end_define

begin_comment
comment|/* special Button Code, passed to GrabButton */
end_comment

begin_define
define|#
directive|define
name|AllTemporary
value|0L
end_define

begin_comment
comment|/* special Resource ID passed to KillClient */
end_comment

begin_define
define|#
directive|define
name|CurrentTime
value|0L
end_define

begin_comment
comment|/* special Time */
end_comment

begin_define
define|#
directive|define
name|NoSymbol
value|0L
end_define

begin_comment
comment|/* special KeySym */
end_comment

begin_comment
comment|/*****************************************************************   * EVENT DEFINITIONS   *****************************************************************/
end_comment

begin_comment
comment|/* Input Event Masks. Used as event-mask window attribute and as arguments    to Grab requests.  Not to be confused with event names.  */
end_comment

begin_define
define|#
directive|define
name|NoEventMask
value|0L
end_define

begin_define
define|#
directive|define
name|KeyPressMask
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|KeyReleaseMask
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|ButtonPressMask
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|ButtonReleaseMask
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|EnterWindowMask
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|LeaveWindowMask
value|(1L<<5)
end_define

begin_define
define|#
directive|define
name|PointerMotionMask
value|(1L<<6)
end_define

begin_define
define|#
directive|define
name|PointerMotionHintMask
value|(1L<<7)
end_define

begin_define
define|#
directive|define
name|Button1MotionMask
value|(1L<<8)
end_define

begin_define
define|#
directive|define
name|Button2MotionMask
value|(1L<<9)
end_define

begin_define
define|#
directive|define
name|Button3MotionMask
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|Button4MotionMask
value|(1L<<11)
end_define

begin_define
define|#
directive|define
name|Button5MotionMask
value|(1L<<12)
end_define

begin_define
define|#
directive|define
name|ButtonMotionMask
value|(1L<<13)
end_define

begin_define
define|#
directive|define
name|KeymapStateMask
value|(1L<<14)
end_define

begin_define
define|#
directive|define
name|ExposureMask
value|(1L<<15)
end_define

begin_define
define|#
directive|define
name|VisibilityChangeMask
value|(1L<<16)
end_define

begin_define
define|#
directive|define
name|StructureNotifyMask
value|(1L<<17)
end_define

begin_define
define|#
directive|define
name|ResizeRedirectMask
value|(1L<<18)
end_define

begin_define
define|#
directive|define
name|SubstructureNotifyMask
value|(1L<<19)
end_define

begin_define
define|#
directive|define
name|SubstructureRedirectMask
value|(1L<<20)
end_define

begin_define
define|#
directive|define
name|FocusChangeMask
value|(1L<<21)
end_define

begin_define
define|#
directive|define
name|PropertyChangeMask
value|(1L<<22)
end_define

begin_define
define|#
directive|define
name|ColormapChangeMask
value|(1L<<23)
end_define

begin_define
define|#
directive|define
name|OwnerGrabButtonMask
value|(1L<<24)
end_define

begin_comment
comment|/* Event names.  Used in "type" field in XEvent structures.  Not to be confused with event masks above.  They start from 2 because 0 and 1 are reserved in the protocol for errors and replies. */
end_comment

begin_define
define|#
directive|define
name|KeyPress
value|2
end_define

begin_define
define|#
directive|define
name|KeyRelease
value|3
end_define

begin_define
define|#
directive|define
name|ButtonPress
value|4
end_define

begin_define
define|#
directive|define
name|ButtonRelease
value|5
end_define

begin_define
define|#
directive|define
name|MotionNotify
value|6
end_define

begin_define
define|#
directive|define
name|EnterNotify
value|7
end_define

begin_define
define|#
directive|define
name|LeaveNotify
value|8
end_define

begin_define
define|#
directive|define
name|FocusIn
value|9
end_define

begin_define
define|#
directive|define
name|FocusOut
value|10
end_define

begin_define
define|#
directive|define
name|KeymapNotify
value|11
end_define

begin_define
define|#
directive|define
name|Expose
value|12
end_define

begin_define
define|#
directive|define
name|GraphicsExpose
value|13
end_define

begin_define
define|#
directive|define
name|NoExpose
value|14
end_define

begin_define
define|#
directive|define
name|VisibilityNotify
value|15
end_define

begin_define
define|#
directive|define
name|CreateNotify
value|16
end_define

begin_define
define|#
directive|define
name|DestroyNotify
value|17
end_define

begin_define
define|#
directive|define
name|UnmapNotify
value|18
end_define

begin_define
define|#
directive|define
name|MapNotify
value|19
end_define

begin_define
define|#
directive|define
name|MapRequest
value|20
end_define

begin_define
define|#
directive|define
name|ReparentNotify
value|21
end_define

begin_define
define|#
directive|define
name|ConfigureNotify
value|22
end_define

begin_define
define|#
directive|define
name|ConfigureRequest
value|23
end_define

begin_define
define|#
directive|define
name|GravityNotify
value|24
end_define

begin_define
define|#
directive|define
name|ResizeRequest
value|25
end_define

begin_define
define|#
directive|define
name|CirculateNotify
value|26
end_define

begin_define
define|#
directive|define
name|CirculateRequest
value|27
end_define

begin_define
define|#
directive|define
name|PropertyNotify
value|28
end_define

begin_define
define|#
directive|define
name|SelectionClear
value|29
end_define

begin_define
define|#
directive|define
name|SelectionRequest
value|30
end_define

begin_define
define|#
directive|define
name|SelectionNotify
value|31
end_define

begin_define
define|#
directive|define
name|ColormapNotify
value|32
end_define

begin_define
define|#
directive|define
name|ClientMessage
value|33
end_define

begin_define
define|#
directive|define
name|MappingNotify
value|34
end_define

begin_define
define|#
directive|define
name|LASTEvent
value|35
end_define

begin_comment
comment|/* must be bigger than any event # */
end_comment

begin_comment
comment|/* Key masks. Used as modifiers to GrabButton and GrabKey, results of QueryPointer,    state in various key-, mouse-, and button-related events. */
end_comment

begin_define
define|#
directive|define
name|ShiftMask
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|LockMask
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|ControlMask
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|Mod1Mask
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|Mod2Mask
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|Mod3Mask
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|Mod4Mask
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|Mod5Mask
value|(1<<7)
end_define

begin_comment
comment|/* modifier names.  Used to build a SetModifierMapping request or    to read a GetModifierMapping request.  These correspond to the    masks defined above. */
end_comment

begin_define
define|#
directive|define
name|ShiftMapIndex
value|0
end_define

begin_define
define|#
directive|define
name|LockMapIndex
value|1
end_define

begin_define
define|#
directive|define
name|ControlMapIndex
value|2
end_define

begin_define
define|#
directive|define
name|Mod1MapIndex
value|3
end_define

begin_define
define|#
directive|define
name|Mod2MapIndex
value|4
end_define

begin_define
define|#
directive|define
name|Mod3MapIndex
value|5
end_define

begin_define
define|#
directive|define
name|Mod4MapIndex
value|6
end_define

begin_define
define|#
directive|define
name|Mod5MapIndex
value|7
end_define

begin_comment
comment|/* button masks.  Used in same manner as Key masks above. Not to be confused    with button names below. */
end_comment

begin_define
define|#
directive|define
name|Button1Mask
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|Button2Mask
value|(1<<9)
end_define

begin_define
define|#
directive|define
name|Button3Mask
value|(1<<10)
end_define

begin_define
define|#
directive|define
name|Button4Mask
value|(1<<11)
end_define

begin_define
define|#
directive|define
name|Button5Mask
value|(1<<12)
end_define

begin_define
define|#
directive|define
name|AnyModifier
value|(1<<15)
end_define

begin_comment
comment|/* used in GrabButton, GrabKey */
end_comment

begin_comment
comment|/* button names. Used as arguments to GrabButton and as detail in ButtonPress    and ButtonRelease events.  Not to be confused with button masks above.    Note that 0 is already defined above as "AnyButton".  */
end_comment

begin_define
define|#
directive|define
name|Button1
value|1
end_define

begin_define
define|#
directive|define
name|Button2
value|2
end_define

begin_define
define|#
directive|define
name|Button3
value|3
end_define

begin_define
define|#
directive|define
name|Button4
value|4
end_define

begin_define
define|#
directive|define
name|Button5
value|5
end_define

begin_comment
comment|/* Notify modes */
end_comment

begin_define
define|#
directive|define
name|NotifyNormal
value|0
end_define

begin_define
define|#
directive|define
name|NotifyGrab
value|1
end_define

begin_define
define|#
directive|define
name|NotifyUngrab
value|2
end_define

begin_define
define|#
directive|define
name|NotifyWhileGrabbed
value|3
end_define

begin_define
define|#
directive|define
name|NotifyHint
value|1
end_define

begin_comment
comment|/* for MotionNotify events */
end_comment

begin_comment
comment|/* Notify detail */
end_comment

begin_define
define|#
directive|define
name|NotifyAncestor
value|0
end_define

begin_define
define|#
directive|define
name|NotifyVirtual
value|1
end_define

begin_define
define|#
directive|define
name|NotifyInferior
value|2
end_define

begin_define
define|#
directive|define
name|NotifyNonlinear
value|3
end_define

begin_define
define|#
directive|define
name|NotifyNonlinearVirtual
value|4
end_define

begin_define
define|#
directive|define
name|NotifyPointer
value|5
end_define

begin_define
define|#
directive|define
name|NotifyPointerRoot
value|6
end_define

begin_define
define|#
directive|define
name|NotifyDetailNone
value|7
end_define

begin_comment
comment|/* Visibility notify */
end_comment

begin_define
define|#
directive|define
name|VisibilityUnobscured
value|0
end_define

begin_define
define|#
directive|define
name|VisibilityPartiallyObscured
value|1
end_define

begin_define
define|#
directive|define
name|VisibilityFullyObscured
value|2
end_define

begin_comment
comment|/* Circulation request */
end_comment

begin_define
define|#
directive|define
name|PlaceOnTop
value|0
end_define

begin_define
define|#
directive|define
name|PlaceOnBottom
value|1
end_define

begin_comment
comment|/* protocol families */
end_comment

begin_define
define|#
directive|define
name|FamilyInternet
value|0
end_define

begin_define
define|#
directive|define
name|FamilyDECnet
value|1
end_define

begin_define
define|#
directive|define
name|FamilyChaos
value|2
end_define

begin_comment
comment|/* Property notification */
end_comment

begin_define
define|#
directive|define
name|PropertyNewValue
value|0
end_define

begin_define
define|#
directive|define
name|PropertyDelete
value|1
end_define

begin_comment
comment|/* Color Map notification */
end_comment

begin_define
define|#
directive|define
name|ColormapUninstalled
value|0
end_define

begin_define
define|#
directive|define
name|ColormapInstalled
value|1
end_define

begin_comment
comment|/* GrabPointer, GrabButton, GrabKeyboard, GrabKey Modes */
end_comment

begin_define
define|#
directive|define
name|GrabModeSync
value|0
end_define

begin_define
define|#
directive|define
name|GrabModeAsync
value|1
end_define

begin_comment
comment|/* GrabPointer, GrabKeyboard reply status */
end_comment

begin_define
define|#
directive|define
name|GrabSuccess
value|0
end_define

begin_define
define|#
directive|define
name|AlreadyGrabbed
value|1
end_define

begin_define
define|#
directive|define
name|GrabInvalidTime
value|2
end_define

begin_define
define|#
directive|define
name|GrabNotViewable
value|3
end_define

begin_define
define|#
directive|define
name|GrabFrozen
value|4
end_define

begin_comment
comment|/* AllowEvents modes */
end_comment

begin_define
define|#
directive|define
name|AsyncPointer
value|0
end_define

begin_define
define|#
directive|define
name|SyncPointer
value|1
end_define

begin_define
define|#
directive|define
name|ReplayPointer
value|2
end_define

begin_define
define|#
directive|define
name|AsyncKeyboard
value|3
end_define

begin_define
define|#
directive|define
name|SyncKeyboard
value|4
end_define

begin_define
define|#
directive|define
name|ReplayKeyboard
value|5
end_define

begin_define
define|#
directive|define
name|AsyncBoth
value|6
end_define

begin_define
define|#
directive|define
name|SyncBoth
value|7
end_define

begin_comment
comment|/* Used in SetInputFocus, GetInputFocus */
end_comment

begin_define
define|#
directive|define
name|RevertToNone
value|(int)None
end_define

begin_define
define|#
directive|define
name|RevertToPointerRoot
value|(int)PointerRoot
end_define

begin_define
define|#
directive|define
name|RevertToParent
value|2
end_define

begin_comment
comment|/*****************************************************************  * ERROR CODES   *****************************************************************/
end_comment

begin_define
define|#
directive|define
name|Success
value|0
end_define

begin_comment
comment|/* everything's okay */
end_comment

begin_define
define|#
directive|define
name|BadRequest
value|1
end_define

begin_comment
comment|/* bad request code */
end_comment

begin_define
define|#
directive|define
name|BadValue
value|2
end_define

begin_comment
comment|/* int parameter out of range */
end_comment

begin_define
define|#
directive|define
name|BadWindow
value|3
end_define

begin_comment
comment|/* parameter not a Window */
end_comment

begin_define
define|#
directive|define
name|BadPixmap
value|4
end_define

begin_comment
comment|/* parameter not a Pixmap */
end_comment

begin_define
define|#
directive|define
name|BadAtom
value|5
end_define

begin_comment
comment|/* parameter not an Atom */
end_comment

begin_define
define|#
directive|define
name|BadCursor
value|6
end_define

begin_comment
comment|/* parameter not a Cursor */
end_comment

begin_define
define|#
directive|define
name|BadFont
value|7
end_define

begin_comment
comment|/* parameter not a Font */
end_comment

begin_define
define|#
directive|define
name|BadMatch
value|8
end_define

begin_comment
comment|/* parameter mismatch */
end_comment

begin_define
define|#
directive|define
name|BadDrawable
value|9
end_define

begin_comment
comment|/* parameter not a Pixmap or Window */
end_comment

begin_define
define|#
directive|define
name|BadAccess
value|10
end_define

begin_comment
comment|/* depending on context: 				 - key/button already grabbed 				 - attempt to free an illegal  				   cmap entry  				- attempt to store into a read-only  				   color map entry.  				- attempt to modify the access control 				   list from other than the local host. 				*/
end_comment

begin_define
define|#
directive|define
name|BadAlloc
value|11
end_define

begin_comment
comment|/* insufficient resources */
end_comment

begin_define
define|#
directive|define
name|BadColor
value|12
end_define

begin_comment
comment|/* no such colormap */
end_comment

begin_define
define|#
directive|define
name|BadGC
value|13
end_define

begin_comment
comment|/* parameter not a GC */
end_comment

begin_define
define|#
directive|define
name|BadIDChoice
value|14
end_define

begin_comment
comment|/* choice not in range or already used */
end_comment

begin_define
define|#
directive|define
name|BadName
value|15
end_define

begin_comment
comment|/* font or color name doesn't exist */
end_comment

begin_define
define|#
directive|define
name|BadLength
value|16
end_define

begin_comment
comment|/* Request length incorrect */
end_comment

begin_define
define|#
directive|define
name|BadImplementation
value|17
end_define

begin_comment
comment|/* server is defective */
end_comment

begin_define
define|#
directive|define
name|FirstExtensionError
value|128
end_define

begin_define
define|#
directive|define
name|LastExtensionError
value|255
end_define

begin_comment
comment|/*****************************************************************  * WINDOW DEFINITIONS   *****************************************************************/
end_comment

begin_comment
comment|/* Window classes used by CreateWindow */
end_comment

begin_comment
comment|/* Note that CopyFromParent is already defined as 0 above */
end_comment

begin_define
define|#
directive|define
name|InputOutput
value|1
end_define

begin_define
define|#
directive|define
name|InputOnly
value|2
end_define

begin_comment
comment|/* Window attributes for CreateWindow and ChangeWindowAttributes */
end_comment

begin_define
define|#
directive|define
name|CWBackPixmap
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|CWBackPixel
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|CWBorderPixmap
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|CWBorderPixel
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|CWBitGravity
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|CWWinGravity
value|(1L<<5)
end_define

begin_define
define|#
directive|define
name|CWBackingStore
value|(1L<<6)
end_define

begin_define
define|#
directive|define
name|CWBackingPlanes
value|(1L<<7)
end_define

begin_define
define|#
directive|define
name|CWBackingPixel
value|(1L<<8)
end_define

begin_define
define|#
directive|define
name|CWOverrideRedirect
value|(1L<<9)
end_define

begin_define
define|#
directive|define
name|CWSaveUnder
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|CWEventMask
value|(1L<<11)
end_define

begin_define
define|#
directive|define
name|CWDontPropagate
value|(1L<<12)
end_define

begin_define
define|#
directive|define
name|CWColormap
value|(1L<<13)
end_define

begin_define
define|#
directive|define
name|CWCursor
value|(1L<<14)
end_define

begin_comment
comment|/* ConfigureWindow structure */
end_comment

begin_define
define|#
directive|define
name|CWX
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|CWY
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|CWWidth
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|CWHeight
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|CWBorderWidth
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|CWSibling
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|CWStackMode
value|(1<<6)
end_define

begin_comment
comment|/* Bit Gravity */
end_comment

begin_define
define|#
directive|define
name|ForgetGravity
value|0
end_define

begin_define
define|#
directive|define
name|NorthWestGravity
value|1
end_define

begin_define
define|#
directive|define
name|NorthGravity
value|2
end_define

begin_define
define|#
directive|define
name|NorthEastGravity
value|3
end_define

begin_define
define|#
directive|define
name|WestGravity
value|4
end_define

begin_define
define|#
directive|define
name|CenterGravity
value|5
end_define

begin_define
define|#
directive|define
name|EastGravity
value|6
end_define

begin_define
define|#
directive|define
name|SouthWestGravity
value|7
end_define

begin_define
define|#
directive|define
name|SouthGravity
value|8
end_define

begin_define
define|#
directive|define
name|SouthEastGravity
value|9
end_define

begin_define
define|#
directive|define
name|StaticGravity
value|10
end_define

begin_comment
comment|/* Window gravity + bit gravity above */
end_comment

begin_define
define|#
directive|define
name|UnmapGravity
value|0
end_define

begin_comment
comment|/* Used in CreateWindow for backing-store hint */
end_comment

begin_define
define|#
directive|define
name|NotUseful
value|0
end_define

begin_define
define|#
directive|define
name|WhenMapped
value|1
end_define

begin_define
define|#
directive|define
name|Always
value|2
end_define

begin_comment
comment|/* Used in GetWindowAttributes reply */
end_comment

begin_define
define|#
directive|define
name|IsUnmapped
value|0
end_define

begin_define
define|#
directive|define
name|IsUnviewable
value|1
end_define

begin_define
define|#
directive|define
name|IsViewable
value|2
end_define

begin_comment
comment|/* Used in ChangeSaveSet */
end_comment

begin_define
define|#
directive|define
name|SetModeInsert
value|0
end_define

begin_define
define|#
directive|define
name|SetModeDelete
value|1
end_define

begin_comment
comment|/* Used in ChangeCloseDownMode */
end_comment

begin_define
define|#
directive|define
name|DestroyAll
value|0
end_define

begin_define
define|#
directive|define
name|RetainPermanent
value|1
end_define

begin_define
define|#
directive|define
name|RetainTemporary
value|2
end_define

begin_comment
comment|/* Window stacking method (in configureWindow) */
end_comment

begin_define
define|#
directive|define
name|Above
value|0
end_define

begin_define
define|#
directive|define
name|Below
value|1
end_define

begin_define
define|#
directive|define
name|TopIf
value|2
end_define

begin_define
define|#
directive|define
name|BottomIf
value|3
end_define

begin_define
define|#
directive|define
name|Opposite
value|4
end_define

begin_comment
comment|/* Circulation direction */
end_comment

begin_define
define|#
directive|define
name|RaiseLowest
value|0
end_define

begin_define
define|#
directive|define
name|LowerHighest
value|1
end_define

begin_comment
comment|/* Property modes */
end_comment

begin_define
define|#
directive|define
name|PropModeReplace
value|0
end_define

begin_define
define|#
directive|define
name|PropModePrepend
value|1
end_define

begin_define
define|#
directive|define
name|PropModeAppend
value|2
end_define

begin_comment
comment|/*****************************************************************  * GRAPHICS DEFINITIONS  *****************************************************************/
end_comment

begin_comment
comment|/* graphics functions, as in GC.alu */
end_comment

begin_define
define|#
directive|define
name|GXclear
value|0x0
end_define

begin_comment
comment|/* 0 */
end_comment

begin_define
define|#
directive|define
name|GXand
value|0x1
end_define

begin_comment
comment|/* src AND dst */
end_comment

begin_define
define|#
directive|define
name|GXandReverse
value|0x2
end_define

begin_comment
comment|/* src AND NOT dst */
end_comment

begin_define
define|#
directive|define
name|GXcopy
value|0x3
end_define

begin_comment
comment|/* src */
end_comment

begin_define
define|#
directive|define
name|GXandInverted
value|0x4
end_define

begin_comment
comment|/* NOT src AND dst */
end_comment

begin_define
define|#
directive|define
name|GXnoop
value|0x5
end_define

begin_comment
comment|/* dst */
end_comment

begin_define
define|#
directive|define
name|GXxor
value|0x6
end_define

begin_comment
comment|/* src XOR dst */
end_comment

begin_define
define|#
directive|define
name|GXor
value|0x7
end_define

begin_comment
comment|/* src OR dst */
end_comment

begin_define
define|#
directive|define
name|GXnor
value|0x8
end_define

begin_comment
comment|/* NOT src AND NOT dst */
end_comment

begin_define
define|#
directive|define
name|GXequiv
value|0x9
end_define

begin_comment
comment|/* NOT src XOR dst */
end_comment

begin_define
define|#
directive|define
name|GXinvert
value|0xa
end_define

begin_comment
comment|/* NOT dst */
end_comment

begin_define
define|#
directive|define
name|GXorReverse
value|0xb
end_define

begin_comment
comment|/* src OR NOT dst */
end_comment

begin_define
define|#
directive|define
name|GXcopyInverted
value|0xc
end_define

begin_comment
comment|/* NOT src */
end_comment

begin_define
define|#
directive|define
name|GXorInverted
value|0xd
end_define

begin_comment
comment|/* NOT src OR dst */
end_comment

begin_define
define|#
directive|define
name|GXnand
value|0xe
end_define

begin_comment
comment|/* NOT src OR NOT dst */
end_comment

begin_define
define|#
directive|define
name|GXset
value|0xf
end_define

begin_comment
comment|/* 1 */
end_comment

begin_comment
comment|/* LineStyle */
end_comment

begin_define
define|#
directive|define
name|LineSolid
value|0
end_define

begin_define
define|#
directive|define
name|LineOnOffDash
value|1
end_define

begin_define
define|#
directive|define
name|LineDoubleDash
value|2
end_define

begin_comment
comment|/* capStyle */
end_comment

begin_define
define|#
directive|define
name|CapNotLast
value|0
end_define

begin_define
define|#
directive|define
name|CapButt
value|1
end_define

begin_define
define|#
directive|define
name|CapRound
value|2
end_define

begin_define
define|#
directive|define
name|CapProjecting
value|3
end_define

begin_comment
comment|/* joinStyle */
end_comment

begin_define
define|#
directive|define
name|JoinMiter
value|0
end_define

begin_define
define|#
directive|define
name|JoinRound
value|1
end_define

begin_define
define|#
directive|define
name|JoinBevel
value|2
end_define

begin_comment
comment|/* fillStyle */
end_comment

begin_define
define|#
directive|define
name|FillSolid
value|0
end_define

begin_define
define|#
directive|define
name|FillTiled
value|1
end_define

begin_define
define|#
directive|define
name|FillStippled
value|2
end_define

begin_define
define|#
directive|define
name|FillOpaqueStippled
value|3
end_define

begin_comment
comment|/* fillRule */
end_comment

begin_define
define|#
directive|define
name|EvenOddRule
value|0
end_define

begin_define
define|#
directive|define
name|WindingRule
value|1
end_define

begin_comment
comment|/* subwindow mode */
end_comment

begin_define
define|#
directive|define
name|ClipByChildren
value|0
end_define

begin_define
define|#
directive|define
name|IncludeInferiors
value|1
end_define

begin_comment
comment|/* SetClipRectangles ordering */
end_comment

begin_define
define|#
directive|define
name|Unsorted
value|0
end_define

begin_define
define|#
directive|define
name|YSorted
value|1
end_define

begin_define
define|#
directive|define
name|YXSorted
value|2
end_define

begin_define
define|#
directive|define
name|YXBanded
value|3
end_define

begin_comment
comment|/* CoordinateMode for drawing routines */
end_comment

begin_define
define|#
directive|define
name|CoordModeOrigin
value|0
end_define

begin_comment
comment|/* relative to the origin */
end_comment

begin_define
define|#
directive|define
name|CoordModePrevious
value|1
end_define

begin_comment
comment|/* relative to previous point */
end_comment

begin_comment
comment|/* Polygon shapes */
end_comment

begin_define
define|#
directive|define
name|Complex
value|0
end_define

begin_comment
comment|/* paths may intersect */
end_comment

begin_define
define|#
directive|define
name|Nonconvex
value|1
end_define

begin_comment
comment|/* no paths intersect, but not convex */
end_comment

begin_define
define|#
directive|define
name|Convex
value|2
end_define

begin_comment
comment|/* wholly convex */
end_comment

begin_comment
comment|/* Arc modes for PolyFillArc */
end_comment

begin_define
define|#
directive|define
name|ArcChord
value|0
end_define

begin_comment
comment|/* join endpoints of arc */
end_comment

begin_define
define|#
directive|define
name|ArcPieSlice
value|1
end_define

begin_comment
comment|/* join endpoints to center of arc */
end_comment

begin_comment
comment|/* GC components: masks used in CreateGC, CopyGC, ChangeGC, OR'ed into    GC.stateChanges */
end_comment

begin_define
define|#
directive|define
name|GCFunction
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|GCPlaneMask
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|GCForeground
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|GCBackground
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|GCLineWidth
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|GCLineStyle
value|(1L<<5)
end_define

begin_define
define|#
directive|define
name|GCCapStyle
value|(1L<<6)
end_define

begin_define
define|#
directive|define
name|GCJoinStyle
value|(1L<<7)
end_define

begin_define
define|#
directive|define
name|GCFillStyle
value|(1L<<8)
end_define

begin_define
define|#
directive|define
name|GCFillRule
value|(1L<<9)
end_define

begin_define
define|#
directive|define
name|GCTile
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|GCStipple
value|(1L<<11)
end_define

begin_define
define|#
directive|define
name|GCTileStipXOrigin
value|(1L<<12)
end_define

begin_define
define|#
directive|define
name|GCTileStipYOrigin
value|(1L<<13)
end_define

begin_define
define|#
directive|define
name|GCFont
value|(1L<<14)
end_define

begin_define
define|#
directive|define
name|GCSubwindowMode
value|(1L<<15)
end_define

begin_define
define|#
directive|define
name|GCGraphicsExposures
value|(1L<<16)
end_define

begin_define
define|#
directive|define
name|GCClipXOrigin
value|(1L<<17)
end_define

begin_define
define|#
directive|define
name|GCClipYOrigin
value|(1L<<18)
end_define

begin_define
define|#
directive|define
name|GCClipMask
value|(1L<<19)
end_define

begin_define
define|#
directive|define
name|GCDashOffset
value|(1L<<20)
end_define

begin_define
define|#
directive|define
name|GCDashList
value|(1L<<21)
end_define

begin_define
define|#
directive|define
name|GCArcMode
value|(1L<<22)
end_define

begin_define
define|#
directive|define
name|GCLastBit
value|22
end_define

begin_comment
comment|/*****************************************************************  * FONTS   *****************************************************************/
end_comment

begin_comment
comment|/* used in QueryFont -- draw direction */
end_comment

begin_define
define|#
directive|define
name|FontLeftToRight
value|0
end_define

begin_define
define|#
directive|define
name|FontRightToLeft
value|1
end_define

begin_define
define|#
directive|define
name|FontChange
value|255
end_define

begin_comment
comment|/*****************************************************************  *  IMAGING   *****************************************************************/
end_comment

begin_comment
comment|/* ImageFormat -- PutImage, GetImage */
end_comment

begin_define
define|#
directive|define
name|XYBitmap
value|0
end_define

begin_comment
comment|/* depth 1, XYFormat */
end_comment

begin_define
define|#
directive|define
name|XYPixmap
value|1
end_define

begin_comment
comment|/* depth == drawable depth */
end_comment

begin_define
define|#
directive|define
name|ZPixmap
value|2
end_define

begin_comment
comment|/* depth == drawable depth */
end_comment

begin_comment
comment|/*****************************************************************  *  COLOR MAP STUFF   *****************************************************************/
end_comment

begin_comment
comment|/* For CreateColormap */
end_comment

begin_define
define|#
directive|define
name|AllocNone
value|0
end_define

begin_comment
comment|/* create map with no entries */
end_comment

begin_define
define|#
directive|define
name|AllocAll
value|1
end_define

begin_comment
comment|/* allocate entire map writeable */
end_comment

begin_comment
comment|/* Flags used in StoreNamedColor, StoreColors */
end_comment

begin_define
define|#
directive|define
name|DoRed
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|DoGreen
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|DoBlue
value|(1<<2)
end_define

begin_comment
comment|/*****************************************************************  * CURSOR STUFF  *****************************************************************/
end_comment

begin_comment
comment|/* QueryBestSize Class */
end_comment

begin_define
define|#
directive|define
name|CursorShape
value|0
end_define

begin_comment
comment|/* largest size that can be displayed */
end_comment

begin_define
define|#
directive|define
name|TileShape
value|1
end_define

begin_comment
comment|/* size tiled fastest */
end_comment

begin_define
define|#
directive|define
name|StippleShape
value|2
end_define

begin_comment
comment|/* size stippled fastest */
end_comment

begin_comment
comment|/*****************************************************************   * KEYBOARD/POINTER STUFF  *****************************************************************/
end_comment

begin_define
define|#
directive|define
name|AutoRepeatModeOff
value|0
end_define

begin_define
define|#
directive|define
name|AutoRepeatModeOn
value|1
end_define

begin_define
define|#
directive|define
name|AutoRepeatModeDefault
value|2
end_define

begin_define
define|#
directive|define
name|LedModeOff
value|0
end_define

begin_define
define|#
directive|define
name|LedModeOn
value|1
end_define

begin_comment
comment|/* masks for ChangeKeyboardControl */
end_comment

begin_define
define|#
directive|define
name|KBKeyClickPercent
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|KBBellPercent
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|KBBellPitch
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|KBBellDuration
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|KBLed
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|KBLedMode
value|(1L<<5)
end_define

begin_define
define|#
directive|define
name|KBKey
value|(1L<<6)
end_define

begin_define
define|#
directive|define
name|KBAutoRepeatMode
value|(1L<<7)
end_define

begin_define
define|#
directive|define
name|MappingSuccess
value|0
end_define

begin_define
define|#
directive|define
name|MappingBusy
value|1
end_define

begin_define
define|#
directive|define
name|MappingFailed
value|2
end_define

begin_define
define|#
directive|define
name|MappingModifier
value|0
end_define

begin_define
define|#
directive|define
name|MappingKeyboard
value|1
end_define

begin_define
define|#
directive|define
name|MappingPointer
value|2
end_define

begin_comment
comment|/*****************************************************************  * SCREEN SAVER STUFF   *****************************************************************/
end_comment

begin_define
define|#
directive|define
name|DontPreferBlanking
value|0
end_define

begin_define
define|#
directive|define
name|PreferBlanking
value|1
end_define

begin_define
define|#
directive|define
name|DefaultBlanking
value|2
end_define

begin_define
define|#
directive|define
name|DisableScreenSaver
value|0
end_define

begin_define
define|#
directive|define
name|DisableScreenInterval
value|0
end_define

begin_define
define|#
directive|define
name|DontAllowExposures
value|0
end_define

begin_define
define|#
directive|define
name|AllowExposures
value|1
end_define

begin_define
define|#
directive|define
name|DefaultExposures
value|2
end_define

begin_comment
comment|/* for ForceScreenSaver */
end_comment

begin_define
define|#
directive|define
name|ScreenSaverReset
value|0
end_define

begin_define
define|#
directive|define
name|ScreenSaverActive
value|1
end_define

begin_comment
comment|/*****************************************************************  * HOSTS AND CONNECTIONS  *****************************************************************/
end_comment

begin_comment
comment|/* for ChangeHosts */
end_comment

begin_define
define|#
directive|define
name|HostInsert
value|0
end_define

begin_define
define|#
directive|define
name|HostDelete
value|1
end_define

begin_comment
comment|/* for ChangeAccessControl */
end_comment

begin_define
define|#
directive|define
name|EnableAccess
value|1
end_define

begin_define
define|#
directive|define
name|DisableAccess
value|0
end_define

begin_comment
comment|/* Display classes  used in opening the connection   * Note that the statically allocated ones are even numbered and the  * dynamically changeable ones are odd numbered */
end_comment

begin_define
define|#
directive|define
name|StaticGray
value|0
end_define

begin_define
define|#
directive|define
name|GrayScale
value|1
end_define

begin_define
define|#
directive|define
name|StaticColor
value|2
end_define

begin_define
define|#
directive|define
name|PseudoColor
value|3
end_define

begin_define
define|#
directive|define
name|TrueColor
value|4
end_define

begin_define
define|#
directive|define
name|DirectColor
value|5
end_define

begin_comment
comment|/* Byte order  used in imageByteOrder and bitmapBitOrder */
end_comment

begin_define
define|#
directive|define
name|LSBFirst
value|0
end_define

begin_define
define|#
directive|define
name|MSBFirst
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* X_H */
end_comment

end_unit

