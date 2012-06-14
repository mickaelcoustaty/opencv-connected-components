# OpenCV connected components (C++ Interface)

For more information -> http://crd-legacy.lbl.gov/~kewu/ps/LBNL-59102.pdf

## Usage:

    cv::Mat image = imread("input.jpeg",0);
    cv::Mat gray;
    cv::cvtColor(image, gray, cv::COLOR_RGB2GRAY);
    cv::Mat thresh;
    cv::threshold(gray, thresh, 100, 255, cv::THRESH_OTSU);
    
    cv::Mat labelImage(thresh.size(), CV_32S);
    int nLabels = connectedComponents(labelImage, thresh, 8);
    
    std::vector<cv::Vec3b> colors;
    colors.push_back(cv::Vec3b(0, 0, 0));//background
    
    for( int label = 1; label < nLabels; ++label )
    {
        colors.push_back( cv::Vec3b( (rand()&255), (rand()&255), (rand()&255) ) );
    }
    
    cv::Mat dst(image.size(), CV_8UC3);        
    for( int r = 0; r < dst.rows; ++r )
    {
        for( int c = 0; c < dst.cols; ++c )
        {
            int label = labelImage.at<int>(r, c);
            cv::Vec3b &pixel = dst.at<cv::Vec3b>(r, c);
            pixel = colors[label];
        }
    }

    cv::imshow("Output",dst);