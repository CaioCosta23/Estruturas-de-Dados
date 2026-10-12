#ifndef _FRAME_H_
#define _FRAME_H_

typedef struct Frame frame;

/**
 * @brief Create (dynamically allovcated memory for) a frame;
 * 
 * @return Frame* Pointer to the Abstract Data Type represent structure thats contains (inicialized) for a frame;
 */
Frame *frameConstruct();

/**
 * @brief Read all innformations to the frame;
 * 
 * @param frame Pointer to the Abstract Data Type represent structure thats contains (update) for a frame;
 */
void readFrame(Frame *frame);

/**
 * @brief Get the ID (identifier) from the frame;
 * 
 * @param frame Pointer to the Abstract Data Type represent structure thats contains (update) for a frame;
 * @return unsigned int Value of ID (identifier) from the frame;
 */
unsigned int getIdFrame(Frame *frame);

/**
 * @brief Get the ID (identifier) to the video from the frame;
 * 
 * @param frame Pointer to the Abstract Data Type represent structure thats contains (update) for a frame;
 * @return char* Pointer to the ID (identifier) to the video from frame;
 */
char *getIdFrameVideo(Frame *frame);

/**
 * @brief Get the timestamp from the frame;
 * 
 * @param frame Pointer to the Abstract Data Type represent structure thats contains (update) for a frame;
 * @return float Value of timestamp from the frame;
 */
float getFrameTimestamp(Frame *frame);

/**
 * @brief Destroy (dynamically free/desallocated memory for) a frame;
 * 
 * @param frame Pointer to the Abstract Data Type represent structure thats contains (update) for a frame;
 */
void frameDestroy(Frame *frame);

#endif