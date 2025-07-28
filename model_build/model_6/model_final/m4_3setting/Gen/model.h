/*
* DEEPCRAFT Studio 5.5.3243+76c4d63272120e1aa149b27cfceadaf33de9e42c
* Copyright © 2023- Imagimob AB, All Rights Reserved.
* 
* Generated at 07/26/2025 01:45:10 UTC. Any changes will be lost.
* 
* Model ID  c3eeaaec-6000-43c6-a260-ce6a8455f718
* 
* Memory    Size                      Efficiency
* Buffers   15360 bytes (RAM)         100 %
* State     160 bytes (RAM)           100 %
* Readonly  284472 bytes (Flash)      100 %
* 
* Backend              tensorflow
* Keras Version        2.15.0
* Backend Model Type   Sequential
* Backend Model Name   m4_3setting
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
* Input Layer                    [60,15]         float      compute
*    shape = [60,15]
* Convolution 1D                 [30,64]         float      compute
*    filters = 64
*    kernel_size = 7
*    dilation_rate = 1
*    strides = 2
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[7,15,64]
* Batch Normalization            [30,64]         float      compute
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 2
*    gamma = float[64]
*    beta = float[64]
*    mean = float[64]
*    variance = float[64]
* Activation                     [30,64]         float      compute
*    activation = relu
*    trainable = True
* Convolution 1D                 [30,64]         float      compute
*    filters = 64
*    kernel_size = 7
*    dilation_rate = 1
*    strides = 1
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[7,64,64]
* Convolution 1D                 [30,64]         float      compute
*    filters = 64
*    kernel_size = 7
*    dilation_rate = 1
*    strides = 1
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[7,64,64]
* Batch Normalization            [30,64]         float      compute
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 2
*    gamma = float[64]
*    beta = float[64]
*    mean = float[64]
*    variance = float[64]
* Activation                     [30,64]         float      compute
*    activation = relu
*    trainable = True
* Max pooling 1D                 [15,64]         float      compute
*    pool_size = 2
*    strides = 2
*    padding = valid
*    trainable = True
* Dropout                        [15,64]         float      compute
*    rate = 0.1
*    trainable = True
* Long Short-Term Memory         [15,20]         float      compute
*    units = 20
*    activation = tanh
*    recurrent_activation = sigmoid
*    use_bias = True
*    return_sequences = True
*    return_state = False
*    stateful = False
*    go_backwards = False
*    trainable = True
*    kernel = float[64,80]
*    recurrent_kernel = float[20,80]
*    bias = float[80]
* Global average pooling 1D      [20]            float      compute
*    trainable = True
* Dense                          [6]             float      compute
*    units = 6
*    use_bias = True
*    activation = linear
*    trainable = True
*    weight = float[20,6]
*    bias = float[6]
* Activation                     [6]             float      compute
*    activation = softmax
*    trainable = True
* 
* Exported functions:
* 
* void IMAI_compute(const float *restrict data_in, float *restrict data_out)
*    Description: Compute a forward pass
*    Parameter data_in is Input of size float[60,15].
*    Parameter data_out is Output of size float[6].
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
* (ACC) Accuracy 95.946 %
* (F1S) F1 Score 95.945 %
* 
* Name of class                                            (unlabelled)          Falling           normal          Sitting        Squatting           static
* (TP) True Positive or Correct Positive Prediction                   0              142              155               16              163               92
* (FN) False Negative or Incorrect Negative Prediction                0                4                5                1                6                8
* (FP) False Positive or Incorrect Positive Prediction                0                2                6                1                9                6
* (TN) True Negative or Correct Negative Prediction                 592              444              426              574              414              486
* (TPR) True Positive Rate or Sensitivity, Recall              100.00 %          97.26 %          96.88 %          94.12 %          96.45 %          92.00 %
* (TNR) True Negative Rate or Specificity, Selectivity         100.00 %          99.55 %          98.61 %          99.83 %          97.87 %          98.78 %
* (PPV) Positive Predictive Value or Precision                 100.00 %          98.61 %          96.27 %          94.12 %          94.77 %          93.88 %
* (NPV) Negative Predictive Value                              100.00 %          99.11 %          98.84 %          99.83 %          98.57 %          98.38 %
* (FNR) False Negative Rate or Miss Rate                       100.00 %           2.74 %           3.12 %           5.88 %           3.55 %           8.00 %
* (FPR) False Positive Rate or Fall-Out                          0.00 %           0.45 %           1.39 %           0.17 %           2.13 %           1.22 %
* (FDR) False Discovery Rate                                   100.00 %           1.39 %           3.73 %           5.88 %           5.23 %           6.12 %
* (FOR) False Omission Rate                                      0.00 %           0.89 %           1.16 %           0.17 %           1.43 %           1.62 %
* (F1S) F1 Score                                               100.00 %          97.93 %          96.57 %          94.12 %          95.60 %          92.93 %
*/


#define IMAI_TEST_AVG_ACC 0.9594594594594594 // Accuracy
#define IMAI_TEST_AVG_F1S 0.9594454723567548 // F1 Score

#define IMAI_TEST_STATS { \
 {name: "(unlabelled)", TP: 0, FN: 0, FP: 0, TN: 592, TPR: 1, TNR: 1, PPV: 1, NPV: 1, FNR: 1, FPR: 0, FDR: 1, FOR: 0, F1S: 1, }, \
 {name: "Falling", TP: 142, FN: 4, FP: 2, TN: 444, TPR: 0.9726027397260, TNR: 0.9955156950672, PPV: 0.9861111111111, NPV: 0.9910714285714, FNR: 0.0273972602739, FPR: 0.0044843049327, FDR: 0.0138888888888, FOR: 0.0089285714285, F1S: 0.9793103448275, }, \
 {name: "Squatting", TP: 163, FN: 6, FP: 9, TN: 414, TPR: 0.9644970414201, TNR: 0.9787234042553, PPV: 0.9476744186046, NPV: 0.9857142857142, FNR: 0.0355029585798, FPR: 0.0212765957446, FDR: 0.0523255813953, FOR: 0.0142857142857, F1S: 0.9560117302052, }, \
 {name: "normal", TP: 155, FN: 5, FP: 6, TN: 426, TPR: 0.96875, TNR: 0.9861111111111, PPV: 0.9627329192546, NPV: 0.9883990719257, FNR: 0.03125, FPR: 0.0138888888888, FDR: 0.0372670807453, FOR: 0.0116009280742, F1S: 0.9657320872274, }, \
 {name: "static", TP: 92, FN: 8, FP: 6, TN: 486, TPR: 0.92, TNR: 0.9878048780487, PPV: 0.9387755102040, NPV: 0.9838056680161, FNR: 0.08, FPR: 0.0121951219512, FDR: 0.0612244897959, FOR: 0.0161943319838, F1S: 0.9292929292929, }, \
 {name: "Sitting", TP: 16, FN: 1, FP: 1, TN: 574, TPR: 0.9411764705882, TNR: 0.9982608695652, PPV: 0.9411764705882, NPV: 0.9982608695652, FNR: 0.0588235294117, FPR: 0.0017391304347, FDR: 0.0588235294117, FOR: 0.0017391304347, F1S: 0.9411764705882, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_test_stats[] = IMAI_TEST_STATS;
#endif

/*
* Tensorflow Train Set
* 
* (ACC) Accuracy 99.513 %
* (F1S) F1 Score 99.513 %
* 
* Name of class                                            (unlabelled)          Falling           normal          Sitting        Squatting           static
* (TP) True Positive or Correct Positive Prediction                   0              659              716               78              759              444
* (FN) False Negative or Incorrect Negative Prediction                0                0                4                0                4                5
* (FP) False Positive or Incorrect Positive Prediction                0                1                5                0                1                6
* (TN) True Negative or Correct Negative Prediction                2669             2009             1944             2591             1905             2214
* (TPR) True Positive Rate or Sensitivity, Recall              100.00 %         100.00 %          99.44 %         100.00 %          99.48 %          98.89 %
* (TNR) True Negative Rate or Specificity, Selectivity         100.00 %          99.95 %          99.74 %         100.00 %          99.95 %          99.73 %
* (PPV) Positive Predictive Value or Precision                 100.00 %          99.85 %          99.31 %         100.00 %          99.87 %          98.67 %
* (NPV) Negative Predictive Value                              100.00 %         100.00 %          99.79 %         100.00 %          99.79 %          99.77 %
* (FNR) False Negative Rate or Miss Rate                       100.00 %           0.00 %           0.56 %           0.00 %           0.52 %           1.11 %
* (FPR) False Positive Rate or Fall-Out                          0.00 %           0.05 %           0.26 %           0.00 %           0.05 %           0.27 %
* (FDR) False Discovery Rate                                   100.00 %           0.15 %           0.69 %           0.00 %           0.13 %           1.33 %
* (FOR) False Omission Rate                                      0.00 %           0.00 %           0.21 %           0.00 %           0.21 %           0.23 %
* (F1S) F1 Score                                               100.00 %          99.92 %          99.38 %         100.00 %          99.67 %          98.78 %
*/


#define IMAI_TRAIN_AVG_ACC 0.9951292618958412 // Accuracy
#define IMAI_TRAIN_AVG_F1S 0.9951310211030633 // F1 Score

#define IMAI_TRAIN_STATS { \
 {name: "(unlabelled)", TP: 0, FN: 0, FP: 0, TN: 2669, TPR: 1, TNR: 1, PPV: 1, NPV: 1, FNR: 1, FPR: 0, FDR: 1, FOR: 0, F1S: 1, }, \
 {name: "Falling", TP: 659, FN: 0, FP: 1, TN: 2009, TPR: 1, TNR: 0.9995024875621, PPV: 0.9984848484848, NPV: 1, FNR: 0, FPR: 0.0004975124378, FDR: 0.0015151515151, FOR: 0, F1S: 0.9992418498862, }, \
 {name: "Squatting", TP: 759, FN: 4, FP: 1, TN: 1905, TPR: 0.9947575360419, TNR: 0.9994753410283, PPV: 0.9986842105263, NPV: 0.9979046621267, FNR: 0.0052424639580, FPR: 0.0005246589716, FDR: 0.0013157894736, FOR: 0.0020953378732, F1S: 0.9967170059093, }, \
 {name: "normal", TP: 716, FN: 4, FP: 5, TN: 1944, TPR: 0.9944444444444, TNR: 0.9974345818368, PPV: 0.9930651872399, NPV: 0.9979466119096, FNR: 0.0055555555555, FPR: 0.0025654181631, FDR: 0.0069348127600, FOR: 0.0020533880903, F1S: 0.9937543372657, }, \
 {name: "static", TP: 444, FN: 5, FP: 6, TN: 2214, TPR: 0.9888641425389, TNR: 0.9972972972972, PPV: 0.9866666666666, NPV: 0.9977467327625, FNR: 0.0111358574610, FPR: 0.0027027027027, FDR: 0.0133333333333, FOR: 0.0022532672374, F1S: 0.9877641824249, }, \
 {name: "Sitting", TP: 78, FN: 0, FP: 0, TN: 2591, TPR: 1, TNR: 1, PPV: 1, NPV: 1, FNR: 0, FPR: 0, FDR: 0, FOR: 0, F1S: 1, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_train_stats[] = IMAI_TRAIN_STATS;
#endif

/*
* Tensorflow Validation Set
* 
* (ACC) Accuracy 95.591 %
* (F1S) F1 Score 95.616 %
* 
* Name of class                                            (unlabelled)          Falling           normal          Sitting        Squatting           static
* (TP) True Positive or Correct Positive Prediction                   0              134              145               17              154               92
* (FN) False Negative or Incorrect Negative Prediction                0                6                8                0                8                3
* (FP) False Positive or Incorrect Positive Prediction                0                1                4                2                8               10
* (TN) True Negative or Correct Negative Prediction                 567              426              410              548              397              462
* (TPR) True Positive Rate or Sensitivity, Recall              100.00 %          95.71 %          94.77 %         100.00 %          95.06 %          96.84 %
* (TNR) True Negative Rate or Specificity, Selectivity         100.00 %          99.77 %          99.03 %          99.64 %          98.02 %          97.88 %
* (PPV) Positive Predictive Value or Precision                 100.00 %          99.26 %          97.32 %          89.47 %          95.06 %          90.20 %
* (NPV) Negative Predictive Value                              100.00 %          98.61 %          98.09 %         100.00 %          98.02 %          99.35 %
* (FNR) False Negative Rate or Miss Rate                       100.00 %           4.29 %           5.23 %           0.00 %           4.94 %           3.16 %
* (FPR) False Positive Rate or Fall-Out                          0.00 %           0.23 %           0.97 %           0.36 %           1.98 %           2.12 %
* (FDR) False Discovery Rate                                   100.00 %           0.74 %           2.68 %          10.53 %           4.94 %           9.80 %
* (FOR) False Omission Rate                                      0.00 %           1.39 %           1.91 %           0.00 %           1.98 %           0.65 %
* (F1S) F1 Score                                               100.00 %          97.45 %          96.03 %          94.44 %          95.06 %          93.40 %
*/


#define IMAI_VALIDATION_AVG_ACC 0.9559082892416225 // Accuracy
#define IMAI_VALIDATION_AVG_F1S 0.9561612230339485 // F1 Score

#define IMAI_VALIDATION_STATS { \
 {name: "(unlabelled)", TP: 0, FN: 0, FP: 0, TN: 567, TPR: 1, TNR: 1, PPV: 1, NPV: 1, FNR: 1, FPR: 0, FDR: 1, FOR: 0, F1S: 1, }, \
 {name: "Falling", TP: 134, FN: 6, FP: 1, TN: 426, TPR: 0.9571428571428, TNR: 0.9976580796252, PPV: 0.9925925925925, NPV: 0.9861111111111, FNR: 0.0428571428571, FPR: 0.0023419203747, FDR: 0.0074074074074, FOR: 0.0138888888888, F1S: 0.9745454545454, }, \
 {name: "Squatting", TP: 154, FN: 8, FP: 8, TN: 397, TPR: 0.9506172839506, TNR: 0.9802469135802, PPV: 0.9506172839506, NPV: 0.9802469135802, FNR: 0.0493827160493, FPR: 0.0197530864197, FDR: 0.0493827160493, FOR: 0.0197530864197, F1S: 0.9506172839506, }, \
 {name: "normal", TP: 145, FN: 8, FP: 4, TN: 410, TPR: 0.9477124183006, TNR: 0.9903381642512, PPV: 0.9731543624161, NPV: 0.9808612440191, FNR: 0.0522875816993, FPR: 0.0096618357487, FDR: 0.0268456375838, FOR: 0.0191387559808, F1S: 0.9602649006622, }, \
 {name: "static", TP: 92, FN: 3, FP: 10, TN: 462, TPR: 0.9684210526315, TNR: 0.9788135593220, PPV: 0.9019607843137, NPV: 0.9935483870967, FNR: 0.0315789473684, FPR: 0.0211864406779, FDR: 0.0980392156862, FOR: 0.0064516129032, F1S: 0.9340101522842, }, \
 {name: "Sitting", TP: 17, FN: 0, FP: 2, TN: 548, TPR: 1, TNR: 0.9963636363636, PPV: 0.8947368421052, NPV: 1, FNR: 0, FPR: 0.0036363636363, FDR: 0.1052631578947, FOR: 0, F1S: 0.9444444444444, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_validation_stats[] = IMAI_VALIDATION_STATS;
#endif

#define IMAI_API_FUNCTION

// All symbols in order
#define IMAI_SYMBOL_MAP {"unlabelled", "Falling", "Squatting", "normal", "static", "Sitting"}

// Model GUID (16 bytes)
#define IMAI_MODEL_ID {0xec, 0xaa, 0xee, 0xc3, 0x00, 0x60, 0xc6, 0x43, 0xa2, 0x60, 0xce, 0x6a, 0x84, 0x55, 0xf7, 0x18}

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

// data_in [60,15] (3600 bytes)
#define IMAI_DATA_IN_COUNT (900)
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

#define IMAI_KEY_MAX (71)



// Return codes
#define IMAI_RET_SUCCESS 0
#define IMAI_RET_NODATA -1
#define IMAI_RET_NOMEM -2

// Exported methods
void IMAI_compute(const float *restrict data_in, float *restrict data_out);
void IMAI_init(void);

#endif /* _IMAI_MODEL_H_ */
