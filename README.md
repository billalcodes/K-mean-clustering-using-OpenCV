# K-mean clustering using OpenCV
 Detecting Lesions using Kmean Clustering
A way to detect lesions is using K mean Clustering. K-Means clustering algorithm is an
unsupervised algorithm and it is used to segment the interest area from the background. It
clusters or partitions the given data into K-clusters or parts based on the K-centroids. Here you
will have only two centroids, one centroid for lesion region. And one for non-lesion region.
Steps:
1. Choose the number of clusters K.
2. Select at random K points, the centroids (not necessarily from your dataset).
3. Assign each data point to the closest centroid → that forms K clusters.
4. Compute and place the new centroid of each cluster.
5. Reassign each data point to the new closest centroid. If any reassignment. took place, go
to step 4, otherwise, the model is ready.

The algorithm applies K-mean clustering on coloured images. Centroid values will be pixel values. (At no point in colored image, pixel
value goes above 255. The Lesion region is darker spot indicating lower pixel value. Rest of the skin is lighter tone indicating higher pixel values.). Once the lesion and non-lesion has been segmented out of the image, the algo marks lesion region cluster using 1 and rest
of the image as 0. The efficiency of the algorithm is checked by compring the resultent images to the pre-corrected images and calculating the Dice Coefficient.