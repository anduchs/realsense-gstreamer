#ifndef APP_CPP_GST_REALSENSE_META_H
#define APP_CPP_GST_REALSENSE_META_H


#include <gst/video/video.h>

#include <string>
#include <memory>

G_BEGIN_DECLS

#define GST_REALSENSE_META_API_TYPE (gst_realsense_meta_api_get_type())
#define GST_REALSENSE_META_INFO  (gst_realsense_meta_get_info())
typedef struct _GstRealsenseMeta GstRealsenseMeta;

using str_ptr = std::unique_ptr<std::string>;
struct _GstRealsenseMeta {
  GstMeta            meta;

  str_ptr cam_model;
  str_ptr cam_serial_number;

  uint exposure = 0;
};

GType gst_realsense_meta_api_get_type (void);
const GstMetaInfo *gst_realsense_meta_get_info (void);
#define gst_buffer_get_realsense_meta(b) ((GstStringMeta*)gst_buffer_get_meta((b),GST_REALSENSE_META_API_TYPE))

GstRealsenseMeta *gst_buffer_add_realsense_meta(GstBuffer* buffer, 
        const std::string model,
        const std::string serial_number,
        uint exposure
        );

// for python access
// const char* gst_buffer_get_realsense_meta_cstring(GstBuffer* buffer);

G_END_DECLS


#endif //APP_CPP_GST_REALSENSE_META_H