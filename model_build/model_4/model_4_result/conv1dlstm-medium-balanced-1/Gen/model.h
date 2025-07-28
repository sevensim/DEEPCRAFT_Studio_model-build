/*
* DEEPCRAFT Studio 5.5.3243+76c4d63272120e1aa149b27cfceadaf33de9e42c
* Copyright © 2023- Imagimob AB, All Rights Reserved.
* 
* Generated at 07/22/2025 12:51:05 UTC. Any changes will be lost.
* 
* Model ID  f2691cfc-4a4b-4922-bfbd-471dd3a02ba1
* 
* Memory    Size                      Efficiency
* Buffers   5520 bytes (RAM)          100 %
* State     4064 bytes (RAM)          100 %
* Readonly  67800 bytes (Flash)       100 %
* 
* Backend              tensorflow
* Keras Version        2.15.0
* Backend Model Type   Sequential
* Backend Model Name   conv1dlstm-medium-balanced-1
* 
* Class Index | Symbol Label
* 0           | unlabelled
* 1           | Falling
* 2           | Squatting
* 3           | normal
* 4           | static
* 5           | Sitting
* 
* Layer                          Shape           Type       Function
* Sliding Window (data points)   [60,15]         float      dequeue
*    window_shape = [60,15]
*    stride = 60
*    buffer_multiplier = 1
* Input Layer                    [60,15]         float      dequeue
*    shape = [60,15]
* Convolution 1D                 [30,16]         float      dequeue
*    filters = 16
*    kernel_size = 5
*    dilation_rate = 1
*    strides = 2
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[5,15,16]
* Batch Normalization            [30,16]         float      dequeue
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 2
*    gamma = float[16]
*    beta = float[16]
*    mean = float[16]
*    variance = float[16]
* Activation                     [30,16]         float      dequeue
*    activation = relu
*    trainable = True
* Convolution 1D                 [15,16]         float      dequeue
*    filters = 16
*    kernel_size = 5
*    dilation_rate = 1
*    strides = 2
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[5,16,16]
* Convolution 1D                 [8,16]          float      dequeue
*    filters = 16
*    kernel_size = 5
*    dilation_rate = 1
*    strides = 2
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[5,16,16]
* Batch Normalization            [8,16]          float      dequeue
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 2
*    gamma = float[16]
*    beta = float[16]
*    mean = float[16]
*    variance = float[16]
* Activation                     [8,16]          float      dequeue
*    activation = relu
*    trainable = True
* Convolution 1D                 [8,32]          float      dequeue
*    filters = 32
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 1
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,16,32]
* Convolution 1D                 [8,32]          float      dequeue
*    filters = 32
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 1
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,32,32]
* Batch Normalization            [8,32]          float      dequeue
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 2
*    gamma = float[32]
*    beta = float[32]
*    mean = float[32]
*    variance = float[32]
* Activation                     [8,32]          float      dequeue
*    activation = relu
*    trainable = True
* Max pooling 1D                 [4,32]          float      dequeue
*    pool_size = 2
*    strides = 2
*    padding = valid
*    trainable = True
* Dropout                        [4,32]          float      dequeue
*    rate = 0.1
*    trainable = True
* Long Short-Term Memory         [4,32]          float      dequeue
*    units = 32
*    activation = tanh
*    recurrent_activation = sigmoid
*    use_bias = True
*    return_sequences = True
*    return_state = False
*    stateful = False
*    go_backwards = False
*    trainable = True
*    kernel = float[32,128]
*    recurrent_kernel = float[32,128]
*    bias = float[128]
* Global average pooling 1D      [32]            float      dequeue
*    trainable = True
* Dense                          [6]             float      dequeue
*    units = 6
*    use_bias = True
*    activation = linear
*    trainable = True
*    weight = float[32,6]
*    bias = float[6]
* Activation                     [6]             float      dequeue
*    activation = softmax
*    trainable = True
* 
* Exported functions:
* 
* int IMAI_dequeue(float *restrict data_out)
*    Description: Dequeue features. RET_SUCCESS (0) on success, RET_NODATA (-1) if no data is available, RET_NOMEM (-2) on internal memory error
*    Parameter data_out is Output of size float[6].
* 
* int IMAI_enqueue(const float *restrict data_in)
*    Description: Enqueue features. Returns SUCCESS (0) on success, else RET_NOMEM (-2) when low on memory.
*    Parameter data_in is Input of size float[15].
* 
* void IMAI_init(void)
*    Description: Initializes buffers to initial state. This function also works as a reset function.
* 
* 
* Disclaimer:
*   The generated code relies on the optimizations done by the C compiler.
*   For example many for-loops of length 1 must be removed by the optimizer.
*   This can only be done if the functions are inlined and simplified.
*   Check disassembly if unsure.
*   tl;dr Compile using gcc with -O3 or -Ofast
*/

#ifndef _IMAI_MODEL_H_
#define _IMAI_MODEL_H_
#ifdef _MSC_VER
#pragma once
#endif

#include <stdint.h>

typedef struct {    
    char *name;
    double TP; // True Positive or Correct Positive Prediction
    double FN; // False Negative or Incorrect Negative Prediction
    double FP; // False Positive or Incorrect Positive Prediction
    double TN; // True Negative or Correct Negative Prediction
    double TPR; // True Positive Rate or Sensitivity, Recall
    double TNR; // True Negative Rate or Specificity, Selectivity
    double PPV; // Positive Predictive Value or Precision
    double NPV; // Negative Predictive Value
    double FNR; // False Negative Rate or Miss Rate
    double FPR; // False Positive Rate or Fall-Out
    double FDR; // False Discovery Rate
    double FOR; // False Omission Rate
    double F1S; // F1 Score
} IMAI_stats;

/*
* Tensorflow Test Set
* 
* (ACC) Accuracy 90.484 %
* (F1S) F1 Score 90.171 %
* 
* Name of class                                            (unlabelled)          Falling           normal          Sitting        Squatting           static
* (TP) True Positive or Correct Positive Prediction                   0              134              142                6              147               94
* (FN) False Negative or Incorrect Negative Prediction                0                9               14               11               18                3
* (FP) False Positive or Incorrect Positive Prediction                0                5               14                2               25                9
* (TN) True Negative or Correct Negative Prediction                 578              430              408              559              388              472
* (TPR) True Positive Rate or Sensitivity, Recall              100.00 %          93.71 %          91.03 %          35.29 %          89.09 %          96.91 %
* (TNR) True Negative Rate or Specificity, Selectivity         100.00 %          98.85 %          96.68 %          99.64 %          93.95 %          98.13 %
* (PPV) Positive Predictive Value or Precision                 100.00 %          96.40 %          91.03 %          75.00 %          85.47 %          91.26 %
* (NPV) Negative Predictive Value                              100.00 %          97.95 %          96.68 %          98.07 %          95.57 %          99.37 %
* (FNR) False Negative Rate or Miss Rate                       100.00 %           6.29 %           8.97 %          64.71 %          10.91 %           3.09 %
* (FPR) False Positive Rate or Fall-Out                          0.00 %           1.15 %           3.32 %           0.36 %           6.05 %           1.87 %
* (FDR) False Discovery Rate                                   100.00 %           3.60 %           8.97 %          25.00 %          14.53 %           8.74 %
* (FOR) False Omission Rate                                      0.00 %           2.05 %           3.32 %           1.93 %           4.43 %           0.63 %
* (F1S) F1 Score                                               100.00 %          95.04 %          91.03 %          48.00 %          87.24 %          94.00 %
*/


#define IMAI_TEST_AVG_ACC 0.9048442906574394 // Accuracy
#define IMAI_TEST_AVG_F1S 0.9017081258770765 // F1 Score

#define IMAI_TEST_STATS { \
 {name: "(unlabelled)", TP: 0, FN: 0, FP: 0, TN: 578, TPR: 1, TNR: 1, PPV: 1, NPV: 1, FNR: 1, FPR: 0, FDR: 1, FOR: 0, F1S: 1, }, \
 {name: "Falling", TP: 134, FN: 9, FP: 5, TN: 430, TPR: 0.9370629370629, TNR: 0.9885057471264, PPV: 0.9640287769784, NPV: 0.9794988610478, FNR: 0.0629370629370, FPR: 0.0114942528735, FDR: 0.0359712230215, FOR: 0.0205011389521, F1S: 0.9503546099290, }, \
 {name: "Squatting", TP: 147, FN: 18, FP: 25, TN: 388, TPR: 0.8909090909090, TNR: 0.9394673123486, PPV: 0.8546511627906, NPV: 0.9556650246305, FNR: 0.1090909090909, FPR: 0.0605326876513, FDR: 0.1453488372093, FOR: 0.0443349753694, F1S: 0.8724035608308, }, \
 {name: "normal", TP: 142, FN: 14, FP: 14, TN: 408, TPR: 0.9102564102564, TNR: 0.9668246445497, PPV: 0.9102564102564, NPV: 0.9668246445497, FNR: 0.0897435897435, FPR: 0.0331753554502, FDR: 0.0897435897435, FOR: 0.0331753554502, F1S: 0.9102564102564, }, \
 {name: "static", TP: 94, FN: 3, FP: 9, TN: 472, TPR: 0.9690721649484, TNR: 0.9812889812889, PPV: 0.9126213592233, NPV: 0.9936842105263, FNR: 0.0309278350515, FPR: 0.0187110187110, FDR: 0.0873786407766, FOR: 0.0063157894736, F1S: 0.94, }, \
 {name: "Sitting", TP: 6, FN: 11, FP: 2, TN: 559, TPR: 0.3529411764705, TNR: 0.9964349376114, PPV: 0.75, NPV: 0.9807017543859, FNR: 0.6470588235294, FPR: 0.0035650623885, FDR: 0.25, FOR: 0.0192982456140, F1S: 0.48, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_test_stats[] = IMAI_TEST_STATS;
#endif

/*
* Tensorflow Train Set
* 
* (ACC) Accuracy 95.058 %
* (F1S) F1 Score 95.016 %
* 
* Name of class                                            (unlabelled)          Falling           normal          Sitting        Squatting           static
* (TP) True Positive or Correct Positive Prediction                   0              649              692               56              733              428
* (FN) False Negative or Incorrect Negative Prediction                0               15               34               23               36               25
* (FP) False Positive or Incorrect Positive Prediction                0                7               42                0               47               37
* (TN) True Negative or Correct Negative Prediction                2691             2020             1923             2612             1875             2201
* (TPR) True Positive Rate or Sensitivity, Recall              100.00 %          97.74 %          95.32 %          70.89 %          95.32 %          94.48 %
* (TNR) True Negative Rate or Specificity, Selectivity         100.00 %          99.65 %          97.86 %         100.00 %          97.55 %          98.35 %
* (PPV) Positive Predictive Value or Precision                 100.00 %          98.93 %          94.28 %         100.00 %          93.97 %          92.04 %
* (NPV) Negative Predictive Value                              100.00 %          99.26 %          98.26 %          99.13 %          98.12 %          98.88 %
* (FNR) False Negative Rate or Miss Rate                       100.00 %           2.26 %           4.68 %          29.11 %           4.68 %           5.52 %
* (FPR) False Positive Rate or Fall-Out                          0.00 %           0.35 %           2.14 %           0.00 %           2.45 %           1.65 %
* (FDR) False Discovery Rate                                   100.00 %           1.07 %           5.72 %           0.00 %           6.03 %           7.96 %
* (FOR) False Omission Rate                                      0.00 %           0.74 %           1.74 %           0.87 %           1.88 %           1.12 %
* (F1S) F1 Score                                               100.00 %          98.33 %          94.79 %          82.96 %          94.64 %          93.25 %
*/


#define IMAI_TRAIN_AVG_ACC 0.950575994054255 // Accuracy
#define IMAI_TRAIN_AVG_F1S 0.950160619945162 // F1 Score

#define IMAI_TRAIN_STATS { \
 {name: "(unlabelled)", TP: 0, FN: 0, FP: 0, TN: 2691, TPR: 1, TNR: 1, PPV: 1, NPV: 1, FNR: 1, FPR: 0, FDR: 1, FOR: 0, F1S: 1, }, \
 {name: "Falling", TP: 649, FN: 15, FP: 7, TN: 2020, TPR: 0.9774096385542, TNR: 0.9965466206216, PPV: 0.9893292682926, NPV: 0.9926289926289, FNR: 0.0225903614457, FPR: 0.0034533793783, FDR: 0.0106707317073, FOR: 0.0073710073710, F1S: 0.9833333333333, }, \
 {name: "Squatting", TP: 733, FN: 36, FP: 47, TN: 1875, TPR: 0.9531859557867, TNR: 0.9755463059313, PPV: 0.9397435897435, NPV: 0.9811616954474, FNR: 0.0468140442132, FPR: 0.0244536940686, FDR: 0.0602564102564, FOR: 0.0188383045525, F1S: 0.9464170432537, }, \
 {name: "normal", TP: 692, FN: 34, FP: 42, TN: 1923, TPR: 0.9531680440771, TNR: 0.9786259541984, PPV: 0.9427792915531, NPV: 0.9826264690853, FNR: 0.0468319559228, FPR: 0.0213740458015, FDR: 0.0572207084468, FOR: 0.0173735309146, F1S: 0.9479452054794, }, \
 {name: "static", TP: 428, FN: 25, FP: 37, TN: 2201, TPR: 0.9448123620309, TNR: 0.9834673815907, PPV: 0.9204301075268, NPV: 0.9887690925426, FNR: 0.0551876379690, FPR: 0.0165326184092, FDR: 0.0795698924731, FOR: 0.0112309074573, F1S: 0.9324618736383, }, \
 {name: "Sitting", TP: 56, FN: 23, FP: 0, TN: 2612, TPR: 0.7088607594936, TNR: 1, PPV: 1, NPV: 0.9912713472485, FNR: 0.2911392405063, FPR: 0, FDR: 0, FOR: 0.0087286527514, F1S: 0.8296296296296, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_train_stats[] = IMAI_TRAIN_STATS;
#endif

/*
* Tensorflow Validation Set
* 
* (ACC) Accuracy 88.014 %
* (F1S) F1 Score 87.741 %
* 
* Name of class                                            (unlabelled)          Falling           normal          Sitting        Squatting           static
* (TP) True Positive or Correct Positive Prediction                   0              128              134                6              143               81
* (FN) False Negative or Incorrect Negative Prediction                0               10               17               10               17               13
* (FP) False Positive or Incorrect Positive Prediction                0                8               20                1               24               14
* (TN) True Negative or Correct Negative Prediction                 559              413              388              542              375              451
* (TPR) True Positive Rate or Sensitivity, Recall              100.00 %          92.75 %          88.74 %          37.50 %          89.38 %          86.17 %
* (TNR) True Negative Rate or Specificity, Selectivity         100.00 %          98.10 %          95.10 %          99.82 %          93.98 %          96.99 %
* (PPV) Positive Predictive Value or Precision                 100.00 %          94.12 %          87.01 %          85.71 %          85.63 %          85.26 %
* (NPV) Negative Predictive Value                              100.00 %          97.64 %          95.80 %          98.19 %          95.66 %          97.20 %
* (FNR) False Negative Rate or Miss Rate                       100.00 %           7.25 %          11.26 %          62.50 %          10.62 %          13.83 %
* (FPR) False Positive Rate or Fall-Out                          0.00 %           1.90 %           4.90 %           0.18 %           6.02 %           3.01 %
* (FDR) False Discovery Rate                                   100.00 %           5.88 %          12.99 %          14.29 %          14.37 %          14.74 %
* (FOR) False Omission Rate                                      0.00 %           2.36 %           4.20 %           1.81 %           4.34 %           2.80 %
* (F1S) F1 Score                                               100.00 %          93.43 %          87.87 %          52.17 %          87.46 %          85.71 %
*/


#define IMAI_VALIDATION_AVG_ACC 0.8801431127012522 // Accuracy
#define IMAI_VALIDATION_AVG_F1S 0.8774138933118644 // F1 Score

#define IMAI_VALIDATION_STATS { \
 {name: "(unlabelled)", TP: 0, FN: 0, FP: 0, TN: 559, TPR: 1, TNR: 1, PPV: 1, NPV: 1, FNR: 1, FPR: 0, FDR: 1, FOR: 0, F1S: 1, }, \
 {name: "Falling", TP: 128, FN: 10, FP: 8, TN: 413, TPR: 0.9275362318840, TNR: 0.9809976247030, PPV: 0.9411764705882, NPV: 0.9763593380614, FNR: 0.0724637681159, FPR: 0.0190023752969, FDR: 0.0588235294117, FOR: 0.0236406619385, F1S: 0.9343065693430, }, \
 {name: "Squatting", TP: 143, FN: 17, FP: 24, TN: 375, TPR: 0.89375, TNR: 0.9398496240601, PPV: 0.8562874251497, NPV: 0.9566326530612, FNR: 0.10625, FPR: 0.0601503759398, FDR: 0.1437125748502, FOR: 0.0433673469387, F1S: 0.8746177370030, }, \
 {name: "normal", TP: 134, FN: 17, FP: 20, TN: 388, TPR: 0.8874172185430, TNR: 0.9509803921568, PPV: 0.8701298701298, NPV: 0.9580246913580, FNR: 0.1125827814569, FPR: 0.0490196078431, FDR: 0.1298701298701, FOR: 0.0419753086419, F1S: 0.8786885245901, }, \
 {name: "static", TP: 81, FN: 13, FP: 14, TN: 451, TPR: 0.8617021276595, TNR: 0.9698924731182, PPV: 0.8526315789473, NPV: 0.9719827586206, FNR: 0.1382978723404, FPR: 0.0301075268817, FDR: 0.1473684210526, FOR: 0.0280172413793, F1S: 0.8571428571428, }, \
 {name: "Sitting", TP: 6, FN: 10, FP: 1, TN: 542, TPR: 0.375, TNR: 0.9981583793738, PPV: 0.8571428571428, NPV: 0.9818840579710, FNR: 0.625, FPR: 0.0018416206261, FDR: 0.1428571428571, FOR: 0.0181159420289, F1S: 0.5217391304347, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_validation_stats[] = IMAI_VALIDATION_STATS;
#endif

#define IMAI_API_QUEUE

// All symbols in order
#define IMAI_SYMBOL_MAP {"unlabelled", "Falling", "Squatting", "normal", "static", "Sitting"}

// Model GUID (16 bytes)
#define IMAI_MODEL_ID {0xfc, 0x1c, 0x69, 0xf2, 0x4b, 0x4a, 0x22, 0x49, 0xbf, 0xbd, 0x47, 0x1d, 0xd3, 0xa0, 0x2b, 0xa1}

// First nibble is bit encoding, second nibble is number of bytes
#define IMAGINET_TYPES_NONE	(0x0)
#define IMAGINET_TYPES_FLOAT32	(0x14)
#define IMAGINET_TYPES_FLOAT64	(0x18)
#define IMAGINET_TYPES_INT8	(0x21)
#define IMAGINET_TYPES_INT16	(0x22)
#define IMAGINET_TYPES_INT32	(0x24)
#define IMAGINET_TYPES_INT64	(0x28)
#define IMAGINET_TYPES_QDYN8	(0x31)
#define IMAGINET_TYPES_QDYN16	(0x32)
#define IMAGINET_TYPES_QDYN32	(0x34)

// data_in [15] (60 bytes)
#define IMAI_DATA_IN_COUNT (15)
#define IMAI_DATA_IN_TYPE float
#define IMAI_DATA_IN_TYPE_ID IMAGINET_TYPES_FLOAT32
#define IMAI_DATA_IN_SCALE (1)
#define IMAI_DATA_IN_OFFSET (0)
#define IMAI_DATA_IN_IS_QUANTIZED (0)

// data_out [6] (24 bytes)
#define IMAI_DATA_OUT_COUNT (6)
#define IMAI_DATA_OUT_TYPE float
#define IMAI_DATA_OUT_TYPE_ID IMAGINET_TYPES_FLOAT32
#define IMAI_DATA_OUT_SCALE (1)
#define IMAI_DATA_OUT_OFFSET (0)
#define IMAI_DATA_OUT_IS_QUANTIZED (0)

#define IMAI_KEY_MAX (82)



// Return codes
#define IMAI_RET_SUCCESS 0
#define IMAI_RET_NODATA -1
#define IMAI_RET_NOMEM -2

// Exported methods
int IMAI_dequeue(float *restrict data_out);
int IMAI_enqueue(const float *restrict data_in);
void IMAI_init(void);

#endif /* _IMAI_MODEL_H_ */
