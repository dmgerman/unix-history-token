begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_define
define|#
directive|define
name|SPIBUS_IVAR
parameter_list|(
name|d
parameter_list|)
value|(struct spibus_ivar *) device_get_ivars(d)
end_define

begin_define
define|#
directive|define
name|SPIBUS_SOFTC
parameter_list|(
name|d
parameter_list|)
value|(struct spibus_softc *) device_get_softc(d)
end_define

begin_struct
struct|struct
name|spibus_softc
block|{
name|device_t
name|dev
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|spibus_ivar
block|{
name|uint32_t
name|cs
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
block|{
name|SPIBUS_IVAR_CS
comment|/* chip select that we're on */
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|SPIBUS_ACCESSOR
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|,
name|T
parameter_list|)
define|\
value|static inline int							\ spibus_get_ ## A(device_t dev, T *t)					\ {									\ 	return BUS_READ_IVAR(device_get_parent(dev), dev,		\ 	    SPIBUS_IVAR_ ## B, (uintptr_t *) t);			\ }
end_define

begin_macro
name|SPIBUS_ACCESSOR
argument_list|(
argument|cs
argument_list|,
argument|CS
argument_list|,
argument|uint32_t
argument_list|)
end_macro

begin_decl_stmt
specifier|extern
name|driver_t
name|spibus_driver
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|devclass_t
name|spibus_devclass
decl_stmt|;
end_decl_stmt

end_unit

