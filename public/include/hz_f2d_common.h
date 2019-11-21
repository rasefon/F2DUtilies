//
// Created by rasefon on 2019/1/18.
//
#ifndef F2DUTILIES_COMMON_H
#define F2DUTILIES_COMMON_H

#include "hz_f2d_macros.h"

BEGIN_HZ_F2D_NAMESPACE

enum HzF2dDataType {
  dt_object = 0,
  dt_void = 1,
  dt_byte = 2,
  dt_int = 3,
  dt_float = 4,
  dt_double = 5,
  dt_varint = 6,
  dt_point_varint = 7,
  // Variable size types
  // Data bytes are prefixed by an integer
  // representing the number of elements in the array.
  dt_byte_array = 32,
  dt_int_array = 33,
  dt_float_array = 34,
  dt_double_array = 35,
  dt_varint_array = 36,
  // Special variable int encoding for point data
  dt_point_varint_array = 37,
  // Well-known data types that help reduce output size for commonly
  // encountered simple geometries
  dt_arc = 38,
  dt_circle = 39,
  dt_circular_arc = 40,
  dt_string = 63,
  // do not want to go into varint range
  dt_last_data_type = 127
};

enum HzF2dSemanticType {
  // For objects with fixed serialization (arc, raster) we don't bother having
  // dedicated semantic for each member
  // and assume the parsing application knows the order they appear. There is
  // still an end-object tag of course
  // which shows where the object ends.
  st_object_member = 0,
  // Simple / fixed size attributes
  st_fill = 1,
  st_fill_off = 2,
  st_clip_off = 3, //unused
  st_layer = 4,
  st_link = 5, //unused
  st_line_weight = 6,
  st_miter_angle = 7,
  st_miter_length = 8,
  st_line_pattern_ref = 9, // unused
  st_back_color = 10, // unused
  st_color = 11,
  st_markup = 12, // unused
  st_object_id = 13,
  st_markup_id = 14,
  st_reset_rel_offset = 15, // unused
  st_font_ref = 16,

  // Compound object opcodes
  // Begin a generic object opcode
  st_begin_object = 32, // unused

  // Style attribute related opcodes. Those are compound objects
  st_clip = 33,
  st_line_caps = 34, // unused
  st_line_join = 35, // unused
  st_line_pattern_def = 36, // unused
  st_font_def = 37,
  st_viewport = 38,

  // Drawables are all objects-typed bounded by begin/end object opcodes

  // Root level document begin
  st_sheet = 42,
  // Circle, Ellipse, Arcs
  st_arc = 43,
  // The grandfather of them all
  st_polyline = 44,
  st_raster = 45, //TODO:wzq
  st_text = 46,
  st_polytriangle = 47,
  st_dot = 48,
  // end object -- could be ending a generic object or drawable, etc.
  st_end_object = 63,

  st_last_semantic_type = 127 // unused
};

END_NAMESPACE

#endif // F2DUTILIES_COMMON_H
