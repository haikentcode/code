from urllib2 import Request,urlopen
from pyPdf import PdfFileWriter,PdfFileReader
from StringIO import StringIO
import time
import threading

class PdfDownloader:

	def __init__(self):
		self.pdfList = []

	def dPdf(self,url,i):
		remoteFile = urlopen(Request(url)).read()
		memoryFile = StringIO(remoteFile)
		pdfFile = PdfFileReader(memoryFile)
		self.pdfList.append(pdfFile)

	def logic1(self):
		start = time.time()
		urls = ["https://btesimages.s3.amazonaws.com/PdfLabelFiles/flipkartShippingLabel_OD107312205540085000-1731220554008500.pdf",
		        "https://btesimages.s3.amazonaws.com/PdfLabelFiles/paytm_packing_slip_order_559338486.pdf",
		        "https://btesimages.s3.amazonaws.com/PdfLabelFiles/paytm_packing_slip_order_559338426.pdf",
		        "https://btesimages.s3.amazonaws.com/PdfLabelFiles/paytm_packing_slip_order_559338357.pdf",
		        "https://btesimages.s3.amazonaws.com/PdfLabelFiles/paytm_packing_slip_order_559338279.pdf",
		        "https://btesimages.s3.amazonaws.com/PdfLabelFiles/404-9012833-0137142_shippinglabel.pdf",
		        "https://btesimages.s3.amazonaws.com/PdfLabelFiles/171-5056321-1155509_shippinglabel.pdf",
		        "https://btesimages.s3.amazonaws.com/PdfLabelFiles/403-4455185-5905913_shippinglabel.pdf",
		        "https://btesimages.s3.amazonaws.com/PdfLabelFiles/paytm_packing_slip_order_559295457.pdf",
		        "https://btesimages.s3.amazonaws.com/PdfLabelFiles/paytm_packing_slip_order_559295397.pdf",
		        "https://btesimages.s3.amazonaws.com/PdfLabelFiles/paytm_packing_slip_order_559148777.pdf",
		        "https://btesimages.s3.amazonaws.com/PdfLabelFiles/paytm_packing_slip_order_559148776.pdf",
		        "https://btesimages.s3.amazonaws.com/PdfLabelFiles/paytm_packing_slip_order_559148775.pdf",
		        "https://btesimages.s3.amazonaws.com/PdfLabelFiles/paytm_packing_slip_order_559148770.pdf",
		        "https://btesimages.s3.amazonaws.com/PdfLabelFiles/SnapDealLabel_19805014659-SLP1140406657.pdf",
		        "https://btesimages.s3.amazonaws.com/PdfLabelFiles/SnapDealLabel_19803429605-SLP1140286741.pdf",
		        "https://btesimages.s3.amazonaws.com/PdfLabelFiles/171-7456146-3809129_shippinglabel.pdf",
		        "https://btesimages.s3.amazonaws.com/PdfLabelFiles/paytm_packing_slip_order_559131926.pdf",
		        "https://btesimages.s3.amazonaws.com/PdfLabelFiles/paytm_packing_slip_order_559131850.pdf",
		        "https://btesimages.s3.amazonaws.com/PdfLabelFiles/ebayShippinglabel_2538921681-15242.pdf",
		        "https://btesimages.s3.amazonaws.com/PdfLabelFiles/ebayShippinglabel_2538853123-15242.pdf",
		        "https://btesimages.s3.amazonaws.com/PdfLabelFiles/171-9284133-0781116_shippinglabel.pdf",
		        "https://btesimages.s3.amazonaws.com/PdfLabelFiles/SnapDealLabel_19801906394-SLP1140178106.pdf",
		        "https://btesimages.s3.amazonaws.com/PdfLabelFiles/171-5670213-6464363_shippinglabel.pdf",
		        "https://btesimages.s3.amazonaws.com/PdfLabelFiles/paytm_packing_slip_order_559087648.pdf",
		        "https://btesimages.s3.amazonaws.com/PdfLabelFiles/171-0998013-5440314_shippinglabel.pdf",
		        "https://btesimages.s3.amazonaws.com/PdfLabelFiles/402-3428884-0889148_shippinglabel.pdf",
		        "https://btesimages.s3.amazonaws.com/PdfLabelFiles/403-3179019-2162765_shippinglabel.pdf",
		        "https://btesimages.s3.amazonaws.com/PdfLabelFiles/402-2892189-3625157_shippinglabel.pdf",
		        "https://btesimages.s3.amazonaws.com/PdfLabelFiles/paytm_packing_slip_order_559045947.pdf",
		        "https://btesimages.s3.amazonaws.com/PdfLabelFiles/paytm_packing_slip_order_559045879.pdf",
		        "https://btesimages.s3.amazonaws.com/PdfLabelFiles/paytm_packing_slip_order_559045815.pdf",
		        "https://btesimages.s3.amazonaws.com/PdfLabelFiles/flipkartShippingLabel_OD107310867834425001-1731086783442500.pdf",
		        "https://btesimages.s3.amazonaws.com/PdfLabelFiles/402-9459255-6661948_shippinglabel.pdf",
		        "https://btesimages.s3.amazonaws.com/PdfLabelFiles/ebayShippinglabel_2538638382-15242.pdf",
		        "https://btesimages.s3.amazonaws.com/PdfLabelFiles/ebayShippinglabel_2538630871-15242.pdf",
		        "https://btesimages.s3.amazonaws.com/PdfLabelFiles/ebayShippinglabel_2538512662-15242.pdf",
		        "https://btesimages.s3.amazonaws.com/PdfLabelFiles/ebayShippinglabel_2538508341-15242.pdf",
		        "https://btesimages.s3.amazonaws.com/PdfLabelFiles/flipkartShippingLabel_OD107310694756347000-1731069475634700.pdf",
		        "https://btesimages.s3.amazonaws.com/PdfLabelFiles/SnapDealLabel_19799680099-SLP1140008175.pdf",
		        "https://btesimages.s3.amazonaws.com/PdfLabelFiles/SnapDealLabel_19799407603-SLP1139999699.pdf",
		        "https://btesimages.s3.amazonaws.com/PdfLabelFiles/SnapDealLabel_19798917481-SLP1139967832.pdf",
		        "https://btesimages.s3.amazonaws.com/PdfLabelFiles/SnapDealLabel_19798845649-SLP1139957984.pdf",
		        "https://btesimages.s3.amazonaws.com/PdfLabelFiles/paytm_packing_slip_order_559010233.pdf",
		        "https://btesimages.s3.amazonaws.com/PdfLabelFiles/paytm_packing_slip_order_559010142.pdf",
		        "https://btesimages.s3.amazonaws.com/PdfLabelFiles/paytm_packing_slip_order_559010038.pdf",
		        "https://btesimages.s3.amazonaws.com/PdfLabelFiles/paytm_packing_slip_order_559007311.pdf",
		        "https://btesimages.s3.amazonaws.com/PdfLabelFiles/SnapDealLabel_19799239237-SLP1139987041.pdf",
		        "https://btesimages.s3.amazonaws.com/PdfLabelFiles/SnapDealLabel_19798716880-SLP1139950403.pdf",
		        "https://btesimages.s3.amazonaws.com/PdfLabelFiles/SnapDealLabel_19787010456-SLP1139961489.pdf",
		        "https://btesimages.s3.amazonaws.com/PdfLabelFiles/SnapDealLabel_19797915979-SLP1139887878.pdf",
		        "https://btesimages.s3.amazonaws.com/PdfLabelFiles/ebayShippinglabel_2538385725-15242.pdf",
		        "https://btesimages.s3.amazonaws.com/PdfLabelFiles/ebayShippinglabel_2538361501-15242.pdf",
		        "https://btesimages.s3.amazonaws.com/PdfLabelFiles/ebayShippinglabel_2538330738-15242.pdf",
		        "https://btesimages.s3.amazonaws.com/PdfLabelFiles/ebayShippinglabel_2538321921-15242.pdf",
		        "https://btesimages.s3.amazonaws.com/PdfLabelFiles/SnapDealLabel_19798049434-SLP1139897601.pdf",
		        "https://btesimages.s3.amazonaws.com/PdfLabelFiles/jabong_161010359170961_ship_label_path.pdf"]
		writer = PdfFileWriter()
		count = 0
		threadLists = []
		for i,url in enumerate(urls):
			thread = threading.Thread(target=self.dPdf,args=(url,i))
			count = count+1
			thread.name = "T%d" % count
			threadLists.append(thread)

		for it in threadLists:
			it.start()

		for it in threadLists:
			it.join()

                for pdf in  self.pdfList:
			for pageNum in xrange(pdf.getNumPages()):
				currentPage = pdf.getPage(pageNum)
				writer.addPage(currentPage)

		end1 = time.time()
		print(end1 - start)
		outputStream = open("output.pdf","wb")
		writer.write(outputStream)
		outputStream.close()
		end = time.time()
		print(end - start)

obj = PdfDownloader()
obj.logic1()
